object Szintmero: TSzintmero
  Left = 8
  Top = 21
  Width = 1173
  Height = 606
  Caption = '  Szintmérõ teszt'
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
  object BuKilep: TLabel
    Left = 776
    Top = 24
    Width = 55
    Height = 20
    Caption = 'Kilépés'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsUnderline]
    ParentColor = False
    ParentFont = False
    OnClick = BuKilepClick
  end
  object LabCsomagok: TLabel
    Left = 8
    Top = 32
    Width = 149
    Height = 16
    Caption = 'Szintmérõ csomagok:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object BuClr: TLabel
    Left = 520
    Top = 24
    Width = 47
    Height = 20
    Caption = 'Törlés'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsUnderline]
    ParentColor = False
    ParentFont = False
    OnClick = BuClrClick
  end
  object GroupMintavetel: TRadioGroup
    Left = 176
    Top = 8
    Width = 241
    Height = 41
    Caption = 'Mintavétel'
    TabOrder = 0
  end
  object BuStart: TRadioButton
    Left = 200
    Top = 24
    Width = 89
    Height = 17
    Caption = 'Start'
    TabOrder = 1
    OnClick = BuStartClick
  end
  object BuStop: TRadioButton
    Left = 312
    Top = 24
    Width = 97
    Height = 17
    Caption = 'Stop'
    Checked = True
    TabOrder = 2
    TabStop = True
    OnClick = BuStopClick
  end
  object Lista: TListBox
    Left = 8
    Top = 56
    Width = 1145
    Height = 505
    ItemHeight = 13
    TabOrder = 3
  end
  object SzintmeroTime: TTimer
    Enabled = False
    OnTimer = SzintmeroTimeTimer
    Left = 8
  end
end
