object Cegnevek: TCegnevek
  Left = 7
  Top = 9
  Width = 437
  Height = 421
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
    Left = 16
    Top = 357
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
    Left = 184
    Top = 357
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
    Left = 104
    Top = 341
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
  object LabCsoport: TLabel
    Left = 128
    Top = 112
    Width = 39
    Height = 13
    Caption = 'Csoport:'
  end
  object BuVissza: TLabel
    Left = 362
    Top = 357
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
    Top = 101
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
    Top = 77
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
    Left = 328
    Top = 104
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
  object Txt: TStringGrid
    Left = 56
    Top = 144
    Width = 305
    Height = 185
    ColCount = 2
    DefaultColWidth = 200
    RowCount = 7
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goAlwaysShowEditor]
    TabOrder = 0
    ColWidths = (
      95
      200)
  end
  object BeCsoport: TEdit
    Left = 176
    Top = 112
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
  object GroupMeglevo: TGroupBox
    Left = 8
    Top = 8
    Width = 409
    Height = 57
    Caption = ' Meglévõ cégadatok '
    TabOrder = 2
    object CegDb: TLabel
      Left = 64
      Top = 21
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
    object LabCegDb: TLabel
      Left = 16
      Top = 24
      Width = 36
      Height = 13
      Caption = 'CegDb:'
    end
    object LabCardDb: TLabel
      Left = 152
      Top = 24
      Width = 39
      Height = 13
      Caption = 'CardDb:'
    end
    object CardDb: TLabel
      Left = 200
      Top = 21
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
    object LabTankDb: TLabel
      Left = 296
      Top = 24
      Width = 42
      Height = 13
      Caption = 'TankDb:'
    end
    object TankDb: TLabel
      Left = 344
      Top = 21
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
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'csv'
    Filter = 'csv|*.csv'
    InitialDir = '.'
    Title = 'Cégadatok mentése'
    Left = 392
  end
end
