object SzintTbl: TSzintTbl
  Left = 7
  Top = 9
  Width = 994
  Height = 704
  Caption = 'Cegnevek'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  OnActivate = FormActivate
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 13
  object BuOlvas: TLabel
    Left = 8
    Top = 637
    Width = 72
    Height = 20
    Caption = 'Kiolvasás'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsUnderline]
    ParentColor = False
    ParentFont = False
    OnClick = BuOlvasClick
  end
  object BuBeir: TLabel
    Left = 176
    Top = 637
    Width = 49
    Height = 20
    Caption = 'Beírás'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsUnderline]
    ParentColor = False
    ParentFont = False
    OnClick = BuBeirClick
  end
  object Uzen: TLabel
    Left = 96
    Top = 621
    Width = 16
    Height = 16
    Caption = '---'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object BuVissza: TLabel
    Left = 354
    Top = 637
    Width = 51
    Height = 20
    Caption = 'Vissza'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsUnderline]
    ParentFont = False
    OnClick = BuVisszaClick
  end
  object BuMentes: TLabel
    Left = 8
    Top = 5
    Width = 55
    Height = 20
    Caption = 'Mentés'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsUnderline]
    ParentColor = False
    ParentFont = False
    OnClick = BuMentesClick
  end
  object FileNev: TLabel
    Left = 16
    Top = 29
    Width = 16
    Height = 16
    Caption = '---'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Txt: TStringGrid
    Left = 32
    Top = 48
    Width = 929
    Height = 569
    ColCount = 9
    DefaultColWidth = 100
    DefaultRowHeight = 18
    RowCount = 121
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goAlwaysShowEditor]
    TabOrder = 0
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'csv'
    Filter = 'csv|*.csv'
    InitialDir = '.'
    Title = 'Cégadatok mentése'
    Left = 392
  end
end
