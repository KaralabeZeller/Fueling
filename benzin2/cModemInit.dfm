object ModemInit: TModemInit
  Left = 17
  Top = 34
  Width = 542
  Height = 278
  Caption = 'Modem inicializálás beállítása'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 40
    Width = 3
    Height = 13
  end
  object Label2: TLabel
    Left = 16
    Top = 16
    Width = 37
    Height = 16
    Caption = 'Init 1:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object BuBeir: TLabel
    Left = 240
    Top = 200
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
  object BuKilep: TLabel
    Left = 400
    Top = 200
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
  object Label4: TLabel
    Left = 16
    Top = 96
    Width = 37
    Height = 16
    Caption = 'Init 2:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object BuOlvas: TLabel
    Left = 48
    Top = 200
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
    Left = 88
    Top = 168
    Width = 16
    Height = 16
    Caption = '---'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clYellow
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Init1: TEdit
    Left = 88
    Top = 12
    Width = 401
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
  end
  object Init2: TEdit
    Left = 88
    Top = 92
    Width = 401
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
  end
end
