#include <vcl.h>
#pragma hdrstop
#include "GridUnit.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

//
//  TCoordGrid definition //////////////////////////////////////
//
__fastcall TCoordGrid::TCoordGrid(TComponent* Owner, TStringGrid* AGrid)
  : TForm(Owner)
{
  Grid->Cells[0][0] = AGrid->Cells[0][0];
  Grid->Cells[1][0] = AGrid->Cells[1][0];
  Grid->Cells[0][1] = AGrid->Cells[0][1];
  Grid->Cells[1][1] = AGrid->Cells[1][1];
}

void __fastcall TCoordGrid::BtnOk_Click(TObject *Sender)
{
  Close();
}

