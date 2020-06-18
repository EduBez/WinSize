#include <vcl.h>
#include <shellapi.h>
#include <memory>
#pragma hdrstop

#include <UtilCls.h>

#include "MainUnit.h"
#include "CaptureUnit.h"
#include "GridUnit.h"

#pragma resource "*.dfm"
TMain *Main;

//
//  global variable
//
bool g_bCapturing = false;

//
//  unit constants
//
const int DINV = 3;

//
//  unit variables
//
int g_iTop;
int g_iLeft;
int g_iWidth;
int g_iHeight;

//
//  TMain definition  //////////////////////////////////////////
//
__fastcall TMain::TMain(TComponent* Owner)
    : TForm    (Owner) ,
      m_tcHand (1)     ,
      m_hWnd1  (NULL)
{
    Screen->Cursors[m_tcHand] = LoadCursor(HInstance, "IDC_HAND");
    LoadIniFile();
}

void __fastcall TMain::CmdCapture_Click(TObject *Sender)
{
  Color = clScrollBar;

  Grid   ->SetFocus();
  RdoBtn1->Checked = false;
  RdoBtn2->Checked = false;

  g_bCapturing = true;
  Capture->Show();
}

void __fastcall TMain::CmdDelete_Click(TObject *Sender)
{
  for (int i = 0; i < ListBox->Items->Count; i++)
    if (ListBox->Selected[i])
      ListBox->Items->Delete(i--);
}

void __fastcall TMain::CmdInsert_Click(TObject *Sender)
{
  if (!Edit->Text.IsEmpty())
  {
    ListBox->Items->Add(Edit->Text);
    Edit->Clear();
  }
}

void __fastcall TMain::CmdQuit_Click(TObject *Sender)
{
  Close();
}

void __fastcall TMain::CmdRun_Click(TObject *Sender)
{
  bool bItems = false;
  for (int i = 0; i < ListBox->Items->Count; i++)
    if (ListBox->Selected[i])
    {
      bItems = true;
      break;
    }
  if (bItems)
  {
    try {
      g_iTop    = Grid->Cells[0][0].ToInt();
      g_iLeft   = Grid->Cells[1][0].ToInt();
      g_iWidth  = Grid->Cells[0][1].ToInt();
      g_iHeight = Grid->Cells[1][1].ToInt();

      EnumWindows((WNDENUMPROC)EnumWindowsProc, 0L);
    }
    catch (EConvertError& E) {
    }
  }
}

void __fastcall TMain::Handler_MouseDown(TObject*     Sender,
                                         TMouseButton Button,
                                         TShiftState  Shift,
                                         int X,
                                         int Y)
{
  if (g_bCapturing && Capture->Visible)
  {
    Visible = false;
    Capture->Visible = false;

    m_bTitle  = Capture->CheckBox1 ->Checked;
    m_iScheme = Capture->RdoButton1->Checked ? 1 :
                Capture->RdoButton2->Checked ? 2 : 0;
    m_hWnd  = NULL;
    m_hWnd1 = NULL;

    SetCapture(Handle);
    Screen->Cursor = m_tcHand;
  }
}

void __fastcall TMain::Handler_MouseMove(TObject* Sender, TShiftState Shift,
  int X, int Y)
{
  if (g_bCapturing && !Capture->Visible)
  {
    POINT pt = {X, Y};
    GetCursorPos(&pt);
    m_hWnd = WindowFromPoint(pt);

    if (m_hWnd != m_hWnd1 && m_hWnd1 == NULL)
    {
      m_hWnd1 = m_hWnd;
      FrameWindow(m_hWnd);
    }
    else if (m_hWnd != m_hWnd1 && m_hWnd1 != NULL)
    {
      FrameWindow(m_hWnd1);
      m_hWnd1 = m_hWnd;
      FrameWindow(m_hWnd);
    }
  }
}

void __fastcall TMain::Handler_MouseUp(TObject* Sender, TMouseButton Button,
  TShiftState Shift, int X, int Y)
{
  if (g_bCapturing && !Capture->Visible)
  {
    ReleaseCapture();
    g_bCapturing = false;

    POINT p = {X, Y};
    ::ClientToScreen(Handle, &p);

    HWND HWnd = WindowFromPoint(p);
    if (HWnd)
    {
      RECT r;
      ::GetWindowRect(HWnd, &r);

      AnsiString sX = int(r.left);
      AnsiString sY = int(r.top);

      AnsiString sW = int(r.right  - r.left);
      AnsiString sH = int(r.bottom - r.top);

      Grid->Cells[0][0] = sX;
      Grid->Cells[1][0] = sY;
      Grid->Cells[0][1] = sW;
      Grid->Cells[1][1] = sH;

      if (m_bTitle)
      {
        GetWindowText(HWnd, m_szBuf, sizeof(m_szBuf));
        if (m_szBuf)
          ListBox->Items->Add(m_szBuf);
      }

      switch (m_iScheme)
      {
        case 1 : Scheme1->Text = sX+";" + sY+";" + sW+";" + sH+";"; break;
        case 2 : Scheme2->Text = sX+";" + sY+";" + sW+";" + sH+";"; break;
      }
    }
    Color   = clBtnFace;
    Visible = true;

    Screen->Cursor = crDefault;
    InvalidateRect(NULL, NULL, true);
  }
}

void __fastcall TMain::OnAction_Execute(TObject *Sender)
{
  TAction* pTa = static_cast<TAction*>(Sender);
  int iTag = pTa->Tag;

  TSpeedButton* pSb = iTag == 1 ? BtnScheme1 : BtnScheme2;
  TPoint pt = pSb->ClientOrigin;

  std::auto_ptr<TCoordGrid> pCg(new TCoordGrid(this, Grid));

  pCg->Left = pt.x;
  pCg->Top  = pt.y + pSb->Height + 1;
  pCg->ShowModal();

  Grid->Cells[0][0] = pCg->Grid->Cells[0][0];
  Grid->Cells[1][0] = pCg->Grid->Cells[1][0];
  Grid->Cells[0][1] = pCg->Grid->Cells[0][1];
  Grid->Cells[1][1] = pCg->Grid->Cells[1][1];

  PutScheme(iTag == 1 ? Scheme1 : Scheme2);
}

void __fastcall TMain::OnAction_Update(TObject *Sender)
{
  TAction* pTa = static_cast<TAction*>(Sender);
  switch (pTa->Tag)
  {
    case 1 : pTa->Enabled = RdoBtn1->Checked; break;
    case 2 : pTa->Enabled = RdoBtn2->Checked; break;
  }
}

void __fastcall TMain::OnEdit_KeyDown(TObject* Sender, WORD& Key,
  TShiftState Shift)
{
  if (Key == VK_RETURN)
    CmdInsert_Click(Sender);
}

void __fastcall TMain::OnFormClose(TObject *Sender, TCloseAction &Action)
{
    SaveIniFile();
}

void __fastcall TMain::OnListBox_DblClick(TObject *Sender)
{
  Edit->Text = ListBox->Items->Strings[ListBox->ItemIndex];
}

void __fastcall TMain::OnRadioButton_Click(TObject *Sender)
{
  TRadioButton* pRb = static_cast<TRadioButton*>(Sender);
  GetScheme(pRb->Tag == 1 ? Scheme1 : Scheme2);
}

bool CALLBACK TMain::EnumWindowsProc(HWND HWnd, LPARAM lParam)
{
  char szText[MAX_PATH];
  GetWindowText(HWnd, szText, sizeof(szText));

  if (szText[0])
    for (int i = 0; i < Main->ListBox->Items->Count; i++)
      if (Main->ListBox->Selected[i])
      {
        AnsiString sItem = Main->ListBox->Items->Strings[i];
        if (sItem.Pos(".lnk"))
        {
          sItem = ExtractFileName(sItem);
          sItem = sItem.SubString(1, sItem.Pos(".lnk") - 1);
        }
        if (AnsiString(szText).Pos(sItem))
        {
          MoveWindow(HWnd, g_iTop, g_iLeft, g_iWidth, g_iHeight, true);
          BringWindowToTop(HWnd);
        }
      }
  return true;
}

void TMain::FrameWindow(HWND HWnd)
{
  HDC hHdc;
  RECT rc;

  hHdc = GetWindowDC(HWnd);
  GetWindowRect(HWnd, &rc);

  OffsetRect(&rc, -rc.left, -rc.top);

  if (!IsRectEmpty(&rc))
  {
    PatBlt(hHdc, rc.left, rc.top, rc.right-rc.left, DINV, DSTINVERT);

    PatBlt(hHdc, rc.left, rc.bottom-DINV, DINV, -(rc.bottom-rc.top-2*DINV),
           DSTINVERT);

    PatBlt(hHdc, rc.right-DINV, rc.top+DINV, DINV, rc.bottom-rc.top-2*DINV,
           DSTINVERT);

    PatBlt(hHdc, rc.right, rc.bottom-DINV, -(rc.right-rc.left), DINV,
           DSTINVERT);
  }
  ReleaseDC(HWnd, hHdc);
}

void TMain::GetScheme(TEdit* Scheme)
{
  int iCol=0, iRow=0, iCnt=0;
  AnsiString sText = Scheme->Text;

  while (int iPos = sText.Pos(";"))
  {
    if (iCnt == 1 || iCnt == 3)
      iCol = 1;
    else if (iCnt == 2) {
      iCol = 0;
      iRow = 1;
    }
    Grid->Cells[iCol][iRow] = sText.SubString(1, iPos-1);
    sText = sText.SubString(iPos+1, sText.Length());
    iCnt++;
  }
}

void TMain::PutScheme(TEdit* Scheme)
{
  Scheme->Text =
    Grid->Cells[0][0] + ";" +
    Grid->Cells[1][0] + ";" +
    Grid->Cells[0][1] + ";" +
    Grid->Cells[1][1] + ";" ;
}

void TMain::LoadIniFile()
{
    TPtr<TIniFile> ini(new TIniFile(ChangeFileExt(Application->ExeName, ".ini")));

    Scheme1->Text = ini->ReadString("Storage", "Scheme1_Text", "");
    Scheme2->Text = ini->ReadString("Storage", "Scheme2_Text", "");

    TPtr<TStringList> l(new TStringList());
    ini->ReadSectionValues("Storage.ListBox_Items", l);

    for (int i=0; i < l->Count; ++i)
    {
        UnicodeString n = l->Names[i];
        UnicodeString v = l->Values[n];
        ListBox->AddItem(v, NULL);
    }
}

void TMain::SaveIniFile()
{
    TPtr<TIniFile> ini(new TIniFile(ChangeFileExt(Application->ExeName, ".ini")));

    ini->WriteString("Storage", "Scheme1_Text", Scheme1->Text);
    ini->WriteString("Storage", "Scheme2_Text", Scheme2->Text);

    if (ListBox->Count)
    {
        for (int i=0; i < ListBox->Count; ++i)
        {
            UnicodeString id = "Item" + IntToStr(i);
            UnicodeString vl = ListBox->Items->Strings[i];
            ini->WriteString("Storage.ListBox_Items", id, vl);
        }
    }
    else {
        ini->WriteString("Storage.ListBox_Items", "Item0", "");
    }
}

void __fastcall TMain::OnFormCanResize(TObject* Sender, int& NewWidth, int& NewHeight, bool& Resize)
{
  Resize = false;
}

