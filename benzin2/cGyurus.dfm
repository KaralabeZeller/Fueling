object Gyurus: TGyurus
  Left = 9
  Top = 538
  Width = 307
  Height = 135
  Caption = 'Gyûrûs pisztoly teszt'
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
  object GroupKapcsolat: TGroupBox
    Left = 5
    Top = 8
    Width = 276
    Height = 81
    Caption = ' Pisztoly kapcsolat: '
    TabOrder = 0
    object LabVan: TLabel
      Left = 8
      Top = 20
      Width = 22
      Height = 13
      Caption = 'Van:'
    end
    object KiVan: TLabel
      Left = 40
      Top = 21
      Width = 9
      Height = 20
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabKod: TLabel
      Left = 72
      Top = 20
      Width = 22
      Height = 13
      Caption = 'Kód:'
    end
    object KiKodHex: TLabel
      Left = 104
      Top = 21
      Width = 150
      Height = 20
      Caption = '00 00 00 00 00 00 00'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object KiKodDec: TLabel
      Left = 104
      Top = 45
      Width = 150
      Height = 20
      Caption = '00 00 00 00 00 00 00'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabIdo: TLabel
      Left = 8
      Top = 44
      Width = 26
      Height = 13
      Caption = 'Time:'
    end
    object KiTime: TLabel
      Left = 40
      Top = 45
      Width = 9
      Height = 20
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
  end
end
