object UjKartyaBe: TUjKartyaBe
  Left = 19
  Top = 158
  Width = 792
  Height = 172
  Caption = 'UjKartyaBe'
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
  object LabMaxLiter: TLabel
    Left = 224
    Top = 16
    Width = 43
    Height = 13
    Caption = 'MaxLiter:'
  end
  object LabMaxDb: TLabel
    Left = 288
    Top = 16
    Width = 37
    Height = 13
    Caption = 'MaxDb:'
  end
  object LabPIN: TLabel
    Left = 352
    Top = 16
    Width = 21
    Height = 13
    Caption = 'PIN:'
  end
  object LabKutak: TLabel
    Left = 416
    Top = 16
    Width = 31
    Height = 13
    Caption = 'Kutak:'
  end
  object LabCsoport: TLabel
    Left = 472
    Top = 16
    Width = 39
    Height = 13
    Caption = 'Csoport:'
  end
  object LabPrint: TLabel
    Left = 536
    Top = 16
    Width = 24
    Height = 13
    Caption = 'Print:'
  end
  object LabNev: TLabel
    Left = 600
    Top = 16
    Width = 68
    Height = 13
    Caption = 'Név [20 betû]:'
  end
  object BuUjkartya: TLabel
    Left = 600
    Top = 103
    Width = 150
    Height = 20
    Caption = 'Új kártya hozzáadás'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsUnderline]
    ParentFont = False
    OnClick = BuUjkartyaClick
  end
  object BuMegse: TLabel
    Left = 232
    Top = 103
    Width = 50
    Height = 20
    Caption = 'Mégse'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsUnderline]
    ParentFont = False
    OnClick = BuMegseClick
  end
  object MaxLit: TEdit
    Left = 224
    Top = 32
    Width = 49
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Text = '00000'
  end
  object MaxDb: TEdit
    Left = 288
    Top = 32
    Width = 49
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Text = '00000'
  end
  object GroupTipus: TGroupBox
    Left = 136
    Top = 16
    Width = 81
    Height = 89
    Caption = 'Tipus'
    TabOrder = 2
    object Ember: TRadioButton
      Left = 8
      Top = 16
      Width = 65
      Height = 17
      Caption = 'Ember'
      TabOrder = 0
    end
    object Auto: TRadioButton
      Left = 8
      Top = 32
      Width = 65
      Height = 17
      Caption = 'Auto'
      Checked = True
      TabOrder = 1
      TabStop = True
    end
    object Mester: TRadioButton
      Left = 8
      Top = 48
      Width = 65
      Height = 17
      Caption = 'Mester'
      TabOrder = 2
    end
    object Szerviz: TRadioButton
      Left = 8
      Top = 64
      Width = 65
      Height = 17
      Caption = 'Szerviz'
      TabOrder = 3
    end
  end
  object Pin: TEdit
    Left = 352
    Top = 32
    Width = 49
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    Text = '00000'
  end
  object Kutak: TEdit
    Left = 416
    Top = 32
    Width = 41
    Height = 24
    CharCase = ecUpperCase
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    Text = '0000'
  end
  object Csoport: TEdit
    Left = 472
    Top = 32
    Width = 49
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    Text = '00000'
  end
  object Print: TEdit
    Left = 536
    Top = 32
    Width = 49
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    Text = '0'
  end
  object Nev: TEdit
    Left = 600
    Top = 32
    Width = 153
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    Text = '00000000010000000002'
  end
  object GroupKartyaID: TGroupBox
    Left = 8
    Top = 16
    Width = 121
    Height = 113
    Caption = ' Kártya ID: '
    TabOrder = 8
    object Id: TEdit
      Left = 4
      Top = 16
      Width = 113
      Height = 24
      Color = clLime
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Text = '00000000000000'
    end
    object Olvaso: TRadioButton
      Left = 8
      Top = 48
      Width = 65
      Height = 17
      Caption = 'Olvasó'
      Checked = True
      TabOrder = 1
      TabStop = True
    end
    object Gyuru: TRadioButton
      Left = 8
      Top = 64
      Width = 65
      Height = 17
      Caption = 'Gyûrû'
      TabOrder = 2
    end
    object Kezi: TRadioButton
      Left = 8
      Top = 80
      Width = 65
      Height = 17
      Caption = 'Kézi'
      TabOrder = 3
    end
  end
end
