object BenzMent: TBenzMent
  Left = 213
  Top = 116
  Width = 536
  Height = 214
  Caption = 'Benzin adatok letöltése'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  OnActivate = FormActivate
  OnClose = FormClose
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 13
  object Hiba: TLabel
    Left = 0
    Top = 72
    Width = 513
    Height = 20
    Alignment = taCenter
    AutoSize = False
    Caption = '-'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object LabKezdoCim: TLabel
    Left = 24
    Top = 24
    Width = 65
    Height = 16
    Caption = 'Kezdõ cím:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    OnClick = BuLetoltClick
  end
  object CimMax: TLabel
    Left = 24
    Top = 40
    Width = 80
    Height = 16
    Caption = '(max. 0x0000)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    OnClick = BuLetoltClick
  end
  object BeKezdoCim: TMaskEdit
    Left = 112
    Top = 24
    Width = 105
    Height = 24
    EditMask = '99999;1;_'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MaxLength = 5
    ParentFont = False
    TabOrder = 0
    Text = '     '
  end
  object BuLetolt: TButton
    Left = 416
    Top = 144
    Width = 89
    Height = 25
    Caption = 'letoltes'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -14
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = BuLetoltClick
  end
  object BuMegszak: TButton
    Left = 16
    Top = 144
    Width = 89
    Height = 25
    Caption = 'megszakitas'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -14
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = BuMegszakClick
  end
  object GroupBox1: TGroupBox
    Left = 232
    Top = 16
    Width = 129
    Height = 33
    TabOrder = 3
    object RadioK4: TRadioButton
      Left = 8
      Top = 10
      Width = 50
      Height = 17
      Caption = 'K4'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioK2: TRadioButton
      Left = 72
      Top = 10
      Width = 50
      Height = 17
      Caption = 'K2'
      TabOrder = 1
    end
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'tnk'
    Filter = 'Tankolások|*.tnk'
    InitialDir = '.'
    Title = 'Tankolási adatok mentése'
    Left = 384
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = 'tnk'
    Filter = 'Tankolások|*.tnk'
    InitialDir = '.'
    Title = 'K2i adatok betöltése'
    Left = 416
  end
  object SaveDialog2: TSaveDialog
    DefaultExt = 'csv'
    Filter = 'Tankolások|*.csv'
    InitialDir = '.'
    Title = 'Tankolási adatok mentése'
    Left = 448
  end
  object OpenDialogCsv: TOpenDialog
    DefaultExt = 'csv'
    Filter = 'Tankolások|*.csv'
    InitialDir = '.'
    Title = 'K2i adatok betöltése'
    Left = 480
  end
end
