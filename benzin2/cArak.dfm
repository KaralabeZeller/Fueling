object Arak: TArak
  Left = 30
  Top = 102
  Width = 332
  Height = 321
  Caption = ' Árak beállítása '
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
  object LabCsoport: TLabel
    Left = 96
    Top = 88
    Width = 39
    Height = 13
    Caption = 'Csoport:'
  end
  object BuOlvas: TLabel
    Left = 8
    Top = 243
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
  object Uzen: TLabel
    Left = 64
    Top = 221
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
  object BuBeir: TLabel
    Left = 144
    Top = 243
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
  object BuVissza: TLabel
    Left = 256
    Top = 243
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
    Top = 85
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
    Top = 61
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
  object BuMegszak: TLabel
    Left = 227
    Top = 88
    Width = 88
    Height = 16
    Caption = 'Megszakítás'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGray
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold, fsUnderline]
    ParentColor = False
    ParentFont = False
    OnClick = BuMegszakClick
  end
  object GroupMeglevo: TGroupBox
    Left = 8
    Top = 8
    Width = 305
    Height = 49
    Caption = ' Meglévõ árak '
    TabOrder = 0
    object ArakDb: TLabel
      Left = 64
      Top = 13
      Width = 40
      Height = 24
      Caption = '0000'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object LabDb: TLabel
      Left = 16
      Top = 16
      Width = 39
      Height = 13
      Caption = 'ArakDb:'
    end
  end
  object BeCsoport: TEdit
    Left = 144
    Top = 88
    Width = 57
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Text = '0'
  end
  object Txt: TStringGrid
    Left = 8
    Top = 120
    Width = 305
    Height = 81
    ColCount = 2
    DefaultColWidth = 200
    RowCount = 3
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goAlwaysShowEditor]
    TabOrder = 2
    ColWidths = (
      95
      200)
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'csv'
    Filter = 'csv|*.csv'
    InitialDir = '.'
    Title = 'Cégadatok mentése'
    Left = 208
  end
end
