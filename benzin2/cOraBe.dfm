object OraBe: TOraBe
  Left = 15
  Top = 336
  Width = 446
  Height = 245
  BorderIcons = [biSystemMenu]
  Caption = 'Óra Beállítás'
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
  object BuVissza: TLabel
    Left = 360
    Top = 167
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
  object GroupKorrekcio: TGroupBox
    Left = 8
    Top = 88
    Width = 321
    Height = 113
    Caption = 'Korrekció'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object LabComment: TLabel
      Left = 112
      Top = 26
      Width = 158
      Height = 16
      Caption = '16384percenként 0..127mp'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object BuKorrBe: TLabel
      Left = 248
      Top = 87
      Width = 49
      Height = 20
      Caption = 'Beírás'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = BuKorrBeClick
    end
    object KiUzen2: TLabel
      Left = 104
      Top = 88
      Width = 65
      Height = 20
      Alignment = taCenter
      AutoSize = False
      Caption = '---'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clYellow
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object KiKorr: TLabel
      Left = 40
      Top = 24
      Width = 27
      Height = 20
      Caption = '000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object BeKorr: TEdit
      Left = 16
      Top = 48
      Width = 81
      Height = 28
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Text = '0'
    end
    object Elore: TRadioButton
      Left = 120
      Top = 48
      Width = 113
      Height = 17
      Caption = 'Elõre (késik)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object Vissza: TRadioButton
      Left = 120
      Top = 72
      Width = 113
      Height = 17
      Caption = 'Vissza (siet)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
  end
  object GroupIdo: TGroupBox
    Left = 8
    Top = 0
    Width = 417
    Height = 81
    Caption = 'Idõ'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object KiDatum: TLabel
      Left = 152
      Top = 16
      Width = 154
      Height = 20
      Caption = '0000/00/00 00:00 n:0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabUtolso: TLabel
      Left = 16
      Top = 40
      Width = 119
      Height = 20
      Caption = 'Utolsó beállítás:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object KiBeall: TLabel
      Left = 152
      Top = 40
      Width = 154
      Height = 20
      Caption = '0000/00/00 00:00 n:0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object BuOrabe: TLabel
      Left = 336
      Top = 39
      Width = 65
      Height = 20
      Caption = 'Beállítás'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = BuOrabeClick
    end
    object KiUzen: TLabel
      Left = 328
      Top = 16
      Width = 81
      Height = 20
      Alignment = taCenter
      AutoSize = False
      Caption = '---'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clYellow
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
  end
end
