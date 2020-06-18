#include <vcl.h>
#pragma hdrstop
#include "CaptureUnit.h"

#pragma resource "*.dfm"
TCapture* Capture;

//
//  unit global variables
//
extern bool g_bCapturing;

//
//  TCapture definition  ///////////////////////////////////////
//
__fastcall TCapture::TCapture(TComponent* Owner)
  : TForm(Owner)
{
  m_sFile = ExtractFilePath(Application->ExeName) + "WinSizeHelp.Rtf";
  Height -= RichEdit->Height;
}

void __fastcall TCapture::CmdClose_Click(TObject *Sender)
{
  Close();
}

void __fastcall TCapture::CmdHelp_Click(TObject *Sender)
{
    RichEdit->Visible = !RichEdit->Visible;

    if (RichEdit->Visible) {
        Height += RichEdit->Height;
    }
    else {
        Height -= RichEdit->Height;
    }
}

void __fastcall TCapture::OnCheckBox2_Click(TObject *Sender)
{
  if (CheckBox2->Checked)
    RdoButton1->Checked = true;
  else
  {
    RdoButton1->Checked = false;
    RdoButton2->Checked = false;
  }
  RdoButton1->Enabled = CheckBox2->Checked;
  RdoButton2->Enabled = CheckBox2->Checked;
}

void __fastcall TCapture::OnForm_Close(TObject *Sender, TCloseAction &Action)
{
  g_bCapturing = false;
  Application->MainForm->Color = clBtnFace;
}

void __fastcall TCapture::OnForm_Show(TObject *Sender)
{
  Top  = Application->MainForm->Top + Application->MainForm->Height + 3;
  Left = Application->MainForm->Left;

  if (!FileExists(m_sFile))
  {
    HRSRC   HRes  = FindResource(HInstance, "IDR_HELPRTF", "RT_HTML");
    HGLOBAL HData = LoadResource(HInstance, HRes);

    TStringList* pSl = new TStringList;

    pSl->Text = (LPCSTR)LockResource(HData);
    pSl->SaveToFile(m_sFile);

    delete pSl;
  }
  RichEdit->Lines->LoadFromFile(m_sFile);
}

