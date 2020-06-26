object KutfoTst: TKutfoTst
  Left = 35
  Top = 33
  Width = 594
  Height = 306
  Caption = ' Kútfõ teszt'
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
  object Label13: TLabel
    Left = 8
    Top = 72
    Width = 17
    Height = 13
    Caption = 'Fej:'
  end
  object Label14: TLabel
    Left = 40
    Top = 72
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
  object Kutfo: TComboBox
    Left = 16
    Top = 0
    Width = 73
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Text = '1.Kútfõ'
    OnChange = KutfoChange
    Items.Strings = (
      '1.Kútfõ'
      '2.Kútfõ'
      '3.Kútfõ'
      '4.Kútfõ'
      '5.Kútfõ'
      '6.Kútfõ'
      '7.Kútfõ'
      '8.Kútfõ'
      '9.Kútfõ'
      '10.Kútfõ'
      '11.Kútfõ'
      '12.Kútfõ'
      '13.Kútfõ'
      '14.Kútfõ'
      '15.Kútfõ')
  end
  object Panel1: TPanel
    Left = 184
    Top = 0
    Width = 329
    Height = 25
    TabOrder = 1
    object Label1: TLabel
      Left = 8
      Top = 4
      Width = 37
      Height = 13
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
      Width = 25
      Height = 13
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
  object GroupKutfo: TGroupBox
    Left = 8
    Top = 32
    Width = 569
    Height = 233
    Caption = ' x. Kútfõ '
    TabOrder = 2
    object LabHiba: TLabel
      Left = 8
      Top = 24
      Width = 25
      Height = 13
      Caption = 'Hiba:'
    end
    object KiHiba: TLabel
      Left = 64
      Top = 24
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
    object LabParancs: TLabel
      Left = 104
      Top = 24
      Width = 42
      Height = 13
      Caption = 'Parancs:'
    end
    object KiParancs: TLabel
      Left = 168
      Top = 24
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
    object LabKimit: TLabel
      Left = 208
      Top = 24
      Width = 24
      Height = 13
      Caption = 'Limit:'
    end
    object KiLimit: TLabel
      Left = 272
      Top = 24
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
    object LabStatusz: TLabel
      Left = 320
      Top = 24
      Width = 38
      Height = 13
      Caption = 'Státusz:'
    end
    object KiStat: TLabel
      Left = 384
      Top = 24
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
    object LabFej: TLabel
      Left = 8
      Top = 64
      Width = 17
      Height = 13
      Caption = 'Fej:'
    end
    object KiFej: TLabel
      Left = 48
      Top = 64
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
    object LabLiterKomp: TLabel
      Left = 8
      Top = 136
      Width = 50
      Height = 13
      Caption = 'LiterKomp:'
    end
    object KiLiterKomp: TLabel
      Left = 72
      Top = 136
      Width = 112
      Height = 20
      Caption = '0000000000.00'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabLiter: TLabel
      Left = 8
      Top = 160
      Width = 23
      Height = 13
      Caption = 'Liter:'
    end
    object KiLiter: TLabel
      Left = 72
      Top = 160
      Width = 112
      Height = 20
      Caption = '0000000000.00'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabKezi: TLabel
      Left = 64
      Top = 64
      Width = 23
      Height = 13
      Caption = 'Kézi:'
    end
    object KiKezi: TLabel
      Left = 104
      Top = 64
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
    object LabSum1: TLabel
      Left = 120
      Top = 64
      Width = 30
      Height = 13
      Caption = 'Sum1:'
    end
    object KiSum1: TLabel
      Left = 160
      Top = 64
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
    object LabSum2: TLabel
      Left = 184
      Top = 64
      Width = 30
      Height = 13
      Caption = 'Sum2:'
    end
    object KiSum2: TLabel
      Left = 224
      Top = 64
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
    object LabLopCl: TLabel
      Left = 248
      Top = 64
      Width = 30
      Height = 13
      Caption = 'LopCl:'
    end
    object KiLopCl: TLabel
      Left = 296
      Top = 64
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
    object LabRele: TLabel
      Left = 312
      Top = 64
      Width = 25
      Height = 13
      Caption = 'Relé:'
    end
    object KiRele: TLabel
      Left = 344
      Top = 64
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
    object LabVez: TLabel
      Left = 368
      Top = 64
      Width = 21
      Height = 13
      Caption = 'Vez:'
    end
    object KiVez: TLabel
      Left = 400
      Top = 64
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
    object LabKomp: TLabel
      Left = 432
      Top = 64
      Width = 30
      Height = 13
      Caption = 'Komp:'
    end
    object KiKomp: TLabel
      Left = 472
      Top = 64
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
    object LabGorgetettKomp: TLabel
      Left = 256
      Top = 136
      Width = 74
      Height = 13
      Caption = 'GörgetettKomp:'
    end
    object KiGorgKomp: TLabel
      Left = 344
      Top = 136
      Width = 112
      Height = 20
      Caption = '0000000000.00'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabGorgetett: TLabel
      Left = 256
      Top = 160
      Width = 47
      Height = 13
      Caption = 'Görgetett:'
    end
    object KiGorg: TLabel
      Left = 344
      Top = 160
      Width = 112
      Height = 20
      Caption = '0000000000.00'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabHomerseklet: TLabel
      Left = 256
      Top = 104
      Width = 62
      Height = 13
      Caption = 'Hõmérséklet:'
    end
    object KiHom: TLabel
      Left = 328
      Top = 104
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
    object LabLiterOld: TLabel
      Left = 8
      Top = 192
      Width = 39
      Height = 13
      Caption = 'LiterOld:'
    end
    object KiLiterOld: TLabel
      Left = 72
      Top = 192
      Width = 112
      Height = 20
      Caption = '0000000000.00'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGray
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabTimeOut: TLabel
      Left = 208
      Top = 192
      Width = 43
      Height = 13
      Caption = 'TimeOut:'
    end
    object KiTimeOut: TLabel
      Left = 264
      Top = 192
      Width = 45
      Height = 20
      Caption = '00000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGray
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabUtovilagitas: TLabel
      Left = 352
      Top = 192
      Width = 59
      Height = 13
      Caption = 'Utóvilágítás:'
    end
    object KiUtoVil: TLabel
      Left = 424
      Top = 192
      Width = 45
      Height = 20
      Caption = '00000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGray
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabGyurus: TLabel
      Left = 8
      Top = 104
      Width = 71
      Height = 13
      Caption = 'GyûrûsPisztoly:'
    end
    object KiPisztoly: TLabel
      Left = 88
      Top = 104
      Width = 9
      Height = 20
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGray
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
  end
end
