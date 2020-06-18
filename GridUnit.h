#ifndef GridUnitH
#define GridUnitH

#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>

//
//  TCoordGrid declaration  ////////////////////////////////////
//
class TCoordGrid : public TForm
{
__published:  // IDE-managed Components
  TPanel *Panel;
  TStringGrid *Grid;

  TLabel *Label1;
  TLabel *Label2;

  TSpeedButton *BtnOk;
  void __fastcall BtnOk_Click(TObject *Sender);

private:      // User declarations

public:       // User declarations
  __fastcall TCoordGrid(TComponent* Owner, TStringGrid* AGrid);
};

#endif

