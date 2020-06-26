object BenzMent: TBenzMent
  Left = 192
  Top = 81
  Width = 318
  Height = 111
  Caption = 'Benzin adatok letöltése'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object BuMegszak: TLabel
    Left = 200
    Top = 56
    Width = 88
    Height = 16
    Caption = 'Megszakítás'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
    OnClick = BuMegszakClick
  end
  object BuLetolt: TLabel
    Left = 24
    Top = 56
    Width = 56
    Height = 16
    Caption = 'Letöltés'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
    OnClick = BuLetoltClick
  end
  object Hiba: TLabel
    Left = 24
    Top = 16
    Width = 8
    Height = 20
    Caption = '-'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'tnk'
    Filter = 'Tankolások|*.tnk'
    Title = 'Tankolási adatok mentése'
    Left = 328
    Top = 8
  end
  object Time: TTimer
    Enabled = False
    Interval = 500
    OnTimer = TimeTimer
    Left = 328
    Top = 40
  end
end
