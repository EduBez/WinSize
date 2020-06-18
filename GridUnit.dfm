object CoordGrid: TCoordGrid
  Left = 350
  Top = 108
  Anchors = []
  AutoSize = True
  BorderIcons = []
  BorderStyle = bsNone
  ClientHeight = 125
  ClientWidth = 113
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDefault
  PixelsPerInch = 96
  TextHeight = 13
  object Panel: TPanel
    Left = 0
    Top = 0
    Width = 113
    Height = 125
    BevelOuter = bvSpace
    BorderStyle = bsSingle
    TabOrder = 0
    object Label1: TLabel
      Left = 10
      Top = 7
      Width = 30
      Height = 13
      Hint = '(Esquerda , Topo)'
      Caption = '(X | Y)'
      ParentShowHint = False
      ShowHint = True
    end
    object Label2: TLabel
      Left = 69
      Top = 71
      Width = 35
      Height = 13
      Hint = '(Largura , Altura)'
      Caption = '(W | H)'
      ParentShowHint = False
      ShowHint = True
    end
    object BtnOk: TSpeedButton
      Left = 19
      Top = 90
      Width = 75
      Height = 23
      Caption = '&Ok'
      Flat = True
      Glyph.Data = {
        DE010000424DDE01000000000000760000002800000024000000120000000100
        0400000000006801000000000000000000001000000010000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333333333330000333333333333333333333333F33333333333
        00003333344333333333333333388F3333333333000033334224333333333333
        338338F3333333330000333422224333333333333833338F3333333300003342
        222224333333333383333338F3333333000034222A22224333333338F338F333
        8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
        33333338F83338F338F33333000033A33333A222433333338333338F338F3333
        0000333333333A222433333333333338F338F33300003333333333A222433333
        333333338F338F33000033333333333A222433333333333338F338F300003333
        33333333A222433333333333338F338F00003333333333333A22433333333333
        3338F38F000033333333333333A223333333333333338F830000333333333333
        333A333333333333333338330000333333333333333333333333333333333333
        0000}
      NumGlyphs = 2
      OnClick = BtnOk_Click
    end
    object Grid: TStringGrid
      Left = 23
      Top = 22
      Width = 65
      Height = 47
      ColCount = 2
      DefaultColWidth = 30
      DefaultRowHeight = 21
      FixedCols = 0
      RowCount = 2
      FixedRows = 0
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goTabs]
      ScrollBars = ssNone
      TabOrder = 0
    end
  end
end
