object TankTst: TTankTst
  Left = 6
  Top = 15
  Width = 597
  Height = 428
  Caption = 'TankTst'
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
  object GroupKutfo: TGroupBox
    Left = 8
    Top = 32
    Width = 569
    Height = 353
    Caption = ' x. Kútfõ '
    TabOrder = 0
    object GroupKezdes: TGroupBox
      Left = 8
      Top = 16
      Width = 553
      Height = 209
      Caption = ' Kezdés '
      TabOrder = 0
      object LabVerzio: TLabel
        Left = 8
        Top = 20
        Width = 32
        Height = 13
        Caption = 'Verzió:'
      end
      object Ki1Verz: TLabel
        Left = 48
        Top = 21
        Width = 36
        Height = 20
        Caption = '0000'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabIdo1: TLabel
        Left = 104
        Top = 20
        Width = 18
        Height = 13
        Caption = 'Idõ:'
      end
      object Ki1Ido: TLabel
        Left = 136
        Top = 21
        Width = 132
        Height = 20
        Caption = '00/00/00 00:00:00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabVezNum: TLabel
        Left = 304
        Top = 20
        Width = 43
        Height = 13
        Caption = 'VezNum:'
      end
      object Ki1VezNum: TLabel
        Left = 360
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
      object LabKutNum: TLabel
        Left = 400
        Top = 20
        Width = 41
        Height = 13
        Caption = 'KutNum:'
      end
      object Ki1Kutnum: TLabel
        Left = 456
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
      object LabEmberNum: TLabel
        Left = 8
        Top = 60
        Width = 55
        Height = 13
        Caption = 'EmberNum:'
      end
      object Ki1EmberNum: TLabel
        Left = 72
        Top = 61
        Width = 36
        Height = 20
        Caption = '0000'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabAutoNum: TLabel
        Left = 8
        Top = 92
        Width = 47
        Height = 13
        Caption = 'AutoNum:'
      end
      object Ki1AutoNum: TLabel
        Left = 72
        Top = 93
        Width = 36
        Height = 20
        Caption = '0000'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabCsoport: TLabel
        Left = 8
        Top = 124
        Width = 39
        Height = 13
        Caption = 'Csoport:'
      end
      object Ki1Csoport: TLabel
        Left = 72
        Top = 125
        Width = 36
        Height = 20
        Caption = '0000'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabEmberId: TLabel
        Left = 128
        Top = 60
        Width = 44
        Height = 13
        Caption = 'EmberID:'
      end
      object Ki1EmberId: TLabel
        Left = 176
        Top = 61
        Width = 135
        Height = 20
        Caption = '000000000000000'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabAutoId: TLabel
        Left = 128
        Top = 92
        Width = 36
        Height = 13
        Caption = 'AutoID:'
      end
      object Ki1AutoId: TLabel
        Left = 176
        Top = 93
        Width = 135
        Height = 20
        Caption = '000000000000000'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabKm: TLabel
        Left = 128
        Top = 124
        Width = 18
        Height = 13
        Caption = 'Km:'
      end
      object Ki1Km: TLabel
        Left = 152
        Top = 125
        Width = 72
        Height = 20
        Caption = '00000000'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabMenlev: TLabel
        Left = 256
        Top = 124
        Width = 38
        Height = 13
        Caption = 'Menlev:'
      end
      object Ki1Menlev: TLabel
        Left = 304
        Top = 125
        Width = 72
        Height = 20
        Caption = '00000000'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabUzemora: TLabel
        Left = 400
        Top = 124
        Width = 45
        Height = 13
        Caption = 'Üzemóra:'
      end
      object Ki1Uzemora: TLabel
        Left = 456
        Top = 125
        Width = 72
        Height = 20
        Caption = '00000000'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabEmber: TLabel
        Left = 320
        Top = 60
        Width = 33
        Height = 13
        Caption = 'Ember:'
      end
      object Ki1EmberNev: TLabel
        Left = 368
        Top = 61
        Width = 117
        Height = 20
        Caption = '1234567890123'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabAuto: TLabel
        Left = 320
        Top = 92
        Width = 25
        Height = 13
        Caption = 'Auto:'
      end
      object Ki1AutoNev: TLabel
        Left = 368
        Top = 93
        Width = 117
        Height = 20
        Caption = '1234567890123'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabSzint: TLabel
        Left = 336
        Top = 180
        Width = 26
        Height = 13
        Caption = 'Szint:'
      end
      object LabGorgKomp: TLabel
        Left = 8
        Top = 156
        Width = 53
        Height = 13
        Caption = 'GörgKomp:'
      end
      object Ki1GorgKomp: TLabel
        Left = 80
        Top = 157
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
        Left = 8
        Top = 180
        Width = 47
        Height = 13
        Caption = 'Görgetett:'
      end
      object Ki1Gorgetett: TLabel
        Left = 80
        Top = 181
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
      object LabEgysAr: TLabel
        Left = 216
        Top = 156
        Width = 36
        Height = 13
        Caption = 'EgysÁr:'
      end
      object Ki2EgysAr: TLabel
        Left = 264
        Top = 157
        Width = 49
        Height = 20
        Caption = '000.00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabSorsz: TLabel
        Left = 456
        Top = 156
        Width = 32
        Height = 13
        Caption = 'Sorsz.:'
      end
      object Ki2Cim: TLabel
        Left = 496
        Top = 157
        Width = 36
        Height = 20
        Caption = '0000'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object KiSzint: TLabel
        Left = 376
        Top = 181
        Width = 36
        Height = 20
        Caption = '0000'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
    end
    object GroupZaras: TGroupBox
      Left = 8
      Top = 240
      Width = 553
      Height = 105
      Caption = ' Zárás '
      TabOrder = 1
      object LabIdo2: TLabel
        Left = 8
        Top = 20
        Width = 18
        Height = 13
        Caption = 'Idõ:'
      end
      object Ki2Ido: TLabel
        Left = 40
        Top = 21
        Width = 132
        Height = 20
        Caption = '00/00/00 00:00:00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabKitKomp: TLabel
        Left = 8
        Top = 50
        Width = 41
        Height = 13
        Caption = 'LitKomp:'
      end
      object Ki2LitKomp: TLabel
        Left = 72
        Top = 51
        Width = 76
        Height = 20
        Caption = '000000.00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabLiter: TLabel
        Left = 8
        Top = 80
        Width = 23
        Height = 13
        Caption = 'Liter:'
      end
      object Ki2Liter: TLabel
        Left = 72
        Top = 81
        Width = 76
        Height = 20
        Caption = '000000.00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabHomers: TLabel
        Left = 232
        Top = 50
        Width = 42
        Height = 13
        Caption = 'Hõmérs.:'
      end
      object Ki2Homer: TLabel
        Left = 280
        Top = 51
        Width = 40
        Height = 20
        Caption = '000.0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabSum: TLabel
        Left = 432
        Top = 80
        Width = 24
        Height = 13
        Caption = 'Sum:'
      end
      object Ki2Sum: TLabel
        Left = 464
        Top = 81
        Width = 28
        Height = 16
        Caption = '0000'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabVegeKod: TLabel
        Left = 184
        Top = 80
        Width = 46
        Height = 13
        Caption = 'Végekód:'
      end
      object Ki2Hibakod: TLabel
        Left = 232
        Top = 81
        Width = 18
        Height = 20
        Caption = '00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabNyomtat: TLabel
        Left = 464
        Top = 20
        Width = 42
        Height = 13
        Caption = 'Nyomtat:'
      end
      object Ki2Nyomtat: TLabel
        Left = 512
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
      object LabNetto: TLabel
        Left = 336
        Top = 20
        Width = 29
        Height = 13
        Caption = 'Netto:'
      end
      object Ki2Arnto: TLabel
        Left = 376
        Top = 21
        Width = 76
        Height = 20
        Caption = '000000.00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LabBrutto: TLabel
        Left = 336
        Top = 50
        Width = 31
        Height = 13
        Caption = 'Brutto:'
      end
      object Ki2Arbto: TLabel
        Left = 376
        Top = 51
        Width = 76
        Height = 20
        Caption = '000000.00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
    end
  end
  object Kutfo: TComboBox
    Left = 16
    Top = 0
    Width = 73
    Height = 21
    ItemHeight = 13
    TabOrder = 1
    Text = '1.Kutfo'
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
    TabOrder = 2
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
end
