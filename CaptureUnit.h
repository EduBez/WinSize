#ifndef CaptureH
#define CaptureH

#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
#include <ComCtrls.hpp>

//
//  TCapture declaration  //////////////////////////////////////
//
class TCapture : public TForm
{
__published:	// IDE-managed Components
  TCheckBox *CheckBox1;
  TCheckBox *CheckBox2;
  TGroupBox *GroupBox;

  TRadioButton *RdoButton1;
  TRadioButton *RdoButton2;
  TRichEdit *RichEdit;

  TSpeedButton *BtnClose;
  TSpeedButton *BtnHelp;

  void __fastcall CmdHelp_Click     (TObject *Sender);

  void __fastcall CmdClose_Click    (TObject *Sender);

  void __fastcall OnCheckBox2_Click (TObject *Sender);

  void __fastcall OnForm_Close      (TObject *Sender,
                                     TCloseAction &Action);

  void __fastcall OnForm_Show       (TObject *Sender);
private:      // User declarations
  AnsiString m_sFile;

public:       // User declarations
  __fastcall TCapture(TComponent* Owner);
};

extern PACKAGE TCapture* Capture;
#endif

 