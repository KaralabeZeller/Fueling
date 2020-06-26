object Teszt: TTeszt
  Left = 56
  Top = 50
  Width = 801
  Height = 477
  Caption = 'Teszt rendszer'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  OnActivate = FormActivate
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 16
  object Ki1: TStringGrid
    Left = 8
    Top = 48
    Width = 777
    Height = 177
    ColCount = 10
    DefaultColWidth = 80
    DefaultRowHeight = 20
    RowCount = 8
    FixedRows = 0
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Fixedsys'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssNone
    TabOrder = 0
    ColWidths = (
      96
      70
      63
      61
      59
      62
      58
      62
      58
      172)
  end
  object BuCim1: TButton
    Left = 8
    Top = 24
    Width = 81
    Height = 24
    Caption = 'RAM'
    TabOrder = 1
    OnClick = BuCim1Click
  end
  object BuCim2: TButton
    Left = 8
    Top = 232
    Width = 81
    Height = 24
    Caption = 'RAM'
    TabOrder = 2
    OnClick = BuCim2Click
  end
  object Ki2: TStringGrid
    Left = 8
    Top = 256
    Width = 777
    Height = 177
    ColCount = 10
    DefaultColWidth = 80
    DefaultRowHeight = 20
    RowCount = 8
    FixedRows = 0
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Fixedsys'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssNone
    TabOrder = 3
    ColWidths = (
      95
      70
      63
      61
      59
      62
      58
      62
      58
      172)
  end
  object Panel1: TPanel
    Left = 200
    Top = 0
    Width = 329
    Height = 25
    TabOrder = 4
    object Label1: TLabel
      Left = 8
      Top = 4
      Width = 45
      Height = 16
      Caption = 'Packet:'
    end
    object PacketKi: TLabel
      Left = 55
      Top = 4
      Width = 90
      Height = 16
      AutoSize = False
      Caption = '0'
      Color = clHighlightText
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
    end
    object Label2: TLabel
      Left = 153
      Top = 4
      Width = 32
      Height = 16
      Caption = 'Error:'
    end
    object ErrorKi: TLabel
      Left = 191
      Top = 4
      Width = 90
      Height = 16
      AutoSize = False
      Caption = '0'
      Color = clHighlightText
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
    end
    object BuStatClr: TButton
      Left = 288
      Top = 4
      Width = 33
      Height = 17
      Caption = 'Clr'
      TabOrder = 0
      OnClick = BuStatClrClick
    end
  end
end
