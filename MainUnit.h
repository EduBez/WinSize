#ifndef MainH
#define MainH

#include <ActnList.hpp>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>
#include <StdCtrls.hpp>
#include <System.Actions.hpp>
#include <System.ImageList.hpp>
#include <System.IniFiles.hpp>
#include <ToolWin.hpp>

//
//  TMain declaration //////////////////////////////////////////
//
class TMain : public TForm
{
__published:	// IDE-managed Components
  TActionList *ActionList;
  TAction *Action1;
  TAction *Action2;

  TEdit *Edit;
  TEdit *Scheme1;
  TEdit *Scheme2;

  TGroupBox *GroupBox1;
  TGroupBox *GroupBox2;

  TLabel *Label1;
  TLabel *Label2;
  TLabel *Label3;
  TLabel *Label4;

  TRadioButton *RdoBtn1;
  TRadioButton *RdoBtn2;

  TListBox *ListBox;

  TSpeedButton* BitBtn1;
  TSpeedButton* BitBtn2;
  TSpeedButton* BitBtn3;
  TSpeedButton* BitBtn5;
  TSpeedButton* BitBtn6;

  TSpeedButton *BtnScheme1;
  TSpeedButton *BtnScheme2;

  TStringGrid *Grid;

  void __fastcall CmdCapture_Click    (TObject *Sender);
  void __fastcall CmdDelete_Click     (TObject *Sender);
  void __fastcall CmdInsert_Click     (TObject *Sender);
  void __fastcall CmdQuit_Click       (TObject *Sender);
  void __fastcall CmdRun_Click        (TObject *Sender);

  void __fastcall Handler_MouseDown   (TObject* Sender,
                                       TMouseButton Button,
                                       TShiftState Shift,
                                       int X, int Y);

  void __fastcall Handler_MouseMove   (TObject* Sender,
                                       TShiftState Shift,
                                       int X, int Y);

  void __fastcall Handler_MouseUp     (TObject* Sender,
                                       TMouseButton Button,
                                       TShiftState Shift,
                                       int X, int Y);

  void __fastcall OnAction_Execute    (TObject *Sender);
  void __fastcall OnAction_Update     (TObject *Sender);

  void __fastcall OnEdit_KeyDown      (TObject *Sender,
                                       WORD &Key,
                                       TShiftState Shift);

  void __fastcall OnFormCanResize     (TObject* Sender,
                                       int&     NewWidth,
                                       int&     NewHeight,
                                       bool&    Resize);

  void __fastcall OnFormClose         (TObject *Sender,
                                       TCloseAction &Action);

  void __fastcall OnListBox_DblClick  (TObject *Sender);
  void __fastcall OnRadioButton_Click (TObject *Sender);



private:			// User declarations
  HWND m_hWnd;
  HWND m_hWnd1;

  bool m_bTitle;
  char m_szBuf[MAX_PATH];
  int  m_tcHand;
  int  m_iScheme;

  void FrameWindow(HWND hWnd);
  void GetScheme(TEdit* Scheme);
  void PutScheme(TEdit* Scheme);

  void LoadIniFile();
  void SaveIniFile();

public:			// User declarations
  __fastcall TMain(TComponent* Owner);
  static bool CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);
};

extern PACKAGE TMain *Main;
#endif

