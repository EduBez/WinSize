object Capture: TCapture
  Left = 350
  Top = 108
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Capturar Coordenadas'
  ClientHeight = 197
  ClientWidth = 387
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clBlack
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = True
  Position = poDefault
  OnClose = OnForm_Close
  OnShow = OnForm_Show
  PixelsPerInch = 96
  TextHeight = 13
  object BtnClose: TSpeedButton
    Left = 278
    Top = 54
    Width = 85
    Height = 23
    Caption = '&Cancelar'
    Flat = True
    Glyph.Data = {
      66010000424D6601000000000000760000002800000016000000140000000100
      040000000000F000000000000000000000001000000010000000000000000000
      8000008000000080800080000000800080008080000080808000C0C0C0000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
      FFFFFFFFFF00FFFFFFFFFFFFFFFFFFFFFF00FFFFFFF77FFFFFFFFFFFFF00FFFF
      FF9117FFFFF97FFFFF00FFFFFF91117FFF9117FFFF00FFFFFF911117F911117F
      FF00FFFFFFF911117111117FFF00FFFFFFFF9111111117FFFF00FFFFFFFFF911
      11117FFFFF00FFFFFFFFFF111117FFFFFF00FFFFFFFFFF911117FFFFFF00FFFF
      FFFFF9111117FFFFFF00FFFFFFFF911171117FFFFF00FFFFFFF91117F91117FF
      FF00FFFFFFF9117FFF91117FFF00FFFFFFFF91FFFFF91117FF00FFFFFFFFFFFF
      FFFF919FFF00FFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFFFFFFFFFFFF00FFFF
      FFFFFFFFFFFFFFFFFF00}
    OnClick = CmdClose_Click
  end
  object BtnHelp: TSpeedButton
    Left = 278
    Top = 23
    Width = 85
    Height = 23
    AllowAllUp = True
    GroupIndex = 1
    Caption = '&Ajuda'
    Flat = True
    Glyph.Data = {
      F6000000424DF600000000000000760000002800000010000000100000000100
      0400000000008000000000000000000000001000000010000000000000000000
      8000008000000080800080000000800080008080000080808000C0C0C0000000
      FF00C0C0C00000FFFF00FF000000C0C0C000FFFF0000FFFFFF00DADADADADADA
      0ADAADADADADADA00DADDADA7777770B07DAADA0000000FF007DDA0FFFBFBFBF
      FF07AD0FBFFF44FFBF07DA0FFFBFFFBFFF07AD0FBFFF47FFBF07DA0FFFBF748F
      FF07AD0FBFFFB747BF07DA0FFF47FF44FF07AD0FBF44B844BF07DA0FFF844448
      FF07AD0FBFFFBFFFBF07DA0FFFBFFFBFFF0AADA00000000000AD}
    OnClick = CmdHelp_Click
  end
  object RichEdit: TRichEdit
    Left = 4
    Top = 105
    Width = 376
    Height = 84
    ReadOnly = True
    TabOrder = 0
    Visible = False
    Zoom = 100
  end
  object GroupBox: TGroupBox
    Left = 4
    Top = 4
    Width = 253
    Height = 94
    Caption = ' Janela Capturada '
    TabOrder = 1
    object CheckBox1: TCheckBox
      Left = 8
      Top = 18
      Width = 204
      Height = 17
      Caption = 'Adicionar a lista de &Janelas'
      TabOrder = 0
    end
    object CheckBox2: TCheckBox
      Left = 8
      Top = 36
      Width = 204
      Height = 17
      Caption = 'Atribuir coordenadas ao &Esquema :'
      TabOrder = 1
      OnClick = OnCheckBox2_Click
    end
    object RdoButton1: TRadioButton
      Left = 16
      Top = 54
      Width = 82
      Height = 17
      Caption = 'Panoramic'
      Enabled = False
      TabOrder = 2
    end
    object RdoButton2: TRadioButton
      Left = 16
      Top = 70
      Width = 82
      Height = 17
      Caption = 'Elevator'
      Enabled = False
      TabOrder = 3
    end
  end
end
