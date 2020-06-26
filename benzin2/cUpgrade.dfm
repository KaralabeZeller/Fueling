object Upgrade: TUpgrade
  Left = 39
  Top = 48
  Width = 795
  Height = 715
  Caption = 'Upgrade'
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
  object GroupProgram: TGroupBox
    Left = 8
    Top = 8
    Width = 761
    Height = 313
    Caption = ' Program letöltés '
    TabOrder = 0
    object BuHexOlvas: TLabel
      Left = 16
      Top = 41
      Width = 145
      Height = 20
      Caption = 'Új program letöltés:'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentColor = False
      ParentFont = False
      OnClick = BuHexOlvasClick
    end
    object NevHexForras: TLabel
      Left = 40
      Top = 65
      Width = 6
      Height = 20
      Caption = '-'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object KiHexResu: TLabel
      Left = 174
      Top = 89
      Width = 8
      Height = 20
      Caption = '-'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object KiHexHiba: TLabel
      Left = 622
      Top = 89
      Width = 6
      Height = 20
      Caption = '-'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object BuUpgradeClr: TLabel
      Left = 16
      Top = 129
      Width = 135
      Height = 20
      Caption = 'K4 upgrade törlés:'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = BuUpgradeClrClick
    end
    object KiFlsClrResu: TLabel
      Left = 622
      Top = 129
      Width = 24
      Height = 20
      Caption = '0%'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object BuUpgradeIr: TLabel
      Left = 16
      Top = 177
      Width = 121
      Height = 20
      Caption = 'K4 upgrade írás:'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = BuUpgradeIrClick
    end
    object KiFlsIrResu: TLabel
      Left = 622
      Top = 177
      Width = 24
      Height = 20
      Caption = '0%'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object BuUpgradeOlv: TLabel
      Left = 16
      Top = 225
      Width = 150
      Height = 20
      Caption = 'K4 upgrade olvasás:'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = BuUpgradeOlvClick
    end
    object KiFlsOlvResu: TLabel
      Left = 622
      Top = 225
      Width = 24
      Height = 20
      Caption = '0%'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object KiLetoltesResu: TLabel
      Left = 176
      Top = 273
      Width = 8
      Height = 20
      Caption = '-'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object BuHexFile: TLabel
      Left = 688
      Top = 12
      Width = 61
      Height = 20
      Caption = 'Hex File'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGray
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentColor = False
      ParentFont = False
      OnClick = BuHexFileClick
    end
    object KiFlsClrCim: TLabel
      Left = 622
      Top = 145
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
    object KiFlsIrCim: TLabel
      Left = 622
      Top = 193
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
    object KiFlsOlvCim: TLabel
      Left = 622
      Top = 241
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
    object TrackFlsClr: TTrackBar
      Left = 168
      Top = 128
      Width = 441
      Height = 45
      Max = 100
      Orientation = trHorizontal
      Frequency = 10
      Position = 0
      SliderVisible = False
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      TabStop = False
      TickMarks = tmBottomRight
      TickStyle = tsAuto
    end
    object TrackFlsIr: TTrackBar
      Left = 168
      Top = 176
      Width = 441
      Height = 45
      Max = 100
      Orientation = trHorizontal
      Frequency = 10
      Position = 0
      SliderVisible = False
      SelEnd = 0
      SelStart = 0
      TabOrder = 1
      TabStop = False
      TickMarks = tmBottomRight
      TickStyle = tsAuto
    end
    object TrackFlsOlv: TTrackBar
      Left = 168
      Top = 224
      Width = 441
      Height = 45
      Max = 100
      Orientation = trHorizontal
      Frequency = 10
      Position = 0
      SliderVisible = False
      SelEnd = 0
      SelStart = 0
      TabOrder = 2
      TabStop = False
      TickMarks = tmBottomRight
      TickStyle = tsAuto
    end
    object RadioAuto: TRadioButton
      Left = 264
      Top = 16
      Width = 113
      Height = 17
      Caption = 'Automatikus'
      Checked = True
      TabOrder = 3
      TabStop = True
      OnClick = RadioAutoClick
    end
    object RadioLepesenkent: TRadioButton
      Left = 448
      Top = 16
      Width = 113
      Height = 17
      Caption = 'Lépésenként'
      TabOrder = 4
      OnClick = RadioLepesenkentClick
    end
  end
  object GroupMemoria: TGroupBox
    Left = 8
    Top = 544
    Width = 761
    Height = 121
    Caption = ' Memória kezelés '
    TabOrder = 1
    object BuDump: TLabel
      Left = 16
      Top = 77
      Width = 108
      Height = 20
      Caption = 'DUMP file írás'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentColor = False
      ParentFont = False
      OnClick = BuDumpClick
    end
    object NevDump: TLabel
      Left = 144
      Top = 93
      Width = 6
      Height = 20
      Caption = '-'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object KiDumpResu: TLabel
      Left = 142
      Top = 69
      Width = 27
      Height = 20
      Caption = '0%'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object BuMemory: TLabel
      Left = 617
      Top = 21
      Width = 125
      Height = 20
      Caption = 'Memória kijelzés'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentColor = False
      ParentFont = False
      OnClick = BuMemoryClick
    end
    object RadioHex: TRadioButton
      Left = 56
      Top = 24
      Width = 113
      Height = 17
      Caption = 'Hex file'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadioHexClick
    end
    object RadioOlv: TRadioButton
      Left = 216
      Top = 24
      Width = 113
      Height = 17
      Caption = 'Program memória'
      TabOrder = 1
      OnClick = RadioOlvClick
    end
  end
  object GroupVerzio: TGroupBox
    Left = 8
    Top = 328
    Width = 761
    Height = 209
    Caption = ' K4 program verzió kezelés '
    TabOrder = 2
    object BuVerzCsere: TLabel
      Left = 643
      Top = 61
      Width = 94
      Height = 20
      Caption = 'Verzió csere'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentColor = False
      ParentFont = False
      OnClick = BuVerzCsereClick
    end
    object BuVerziOlv: TLabel
      Left = 16
      Top = 29
      Width = 139
      Height = 20
      Caption = 'Élõ verzió olvasás:'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentColor = False
      ParentFont = False
      OnClick = BuVerziOlvClick
    end
    object BuProgramOlv: TLabel
      Left = 16
      Top = 125
      Width = 140
      Height = 20
      Caption = 'program kiolvasás:'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentColor = False
      ParentFont = False
      OnClick = BuProgramOlvClick
    end
    object KiPrgReadResu: TLabel
      Left = 622
      Top = 125
      Width = 24
      Height = 20
      Caption = '0%'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object KiPrgReadCim: TLabel
      Left = 622
      Top = 149
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
    object KiVerzio: TLabel
      Left = 176
      Top = 29
      Width = 8
      Height = 20
      Caption = '-'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabAllapot: TLabel
      Left = 16
      Top = 61
      Width = 114
      Height = 20
      Caption = 'Kútfõk állapota:'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object BuToltoCsere: TLabel
      Left = 331
      Top = 173
      Width = 146
      Height = 20
      Caption = 'Program töltõ csere'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentColor = False
      ParentFont = False
      OnClick = BuToltoCsereClick
    end
    object TrackPrgRead: TTrackBar
      Left = 168
      Top = 124
      Width = 441
      Height = 45
      Max = 100
      Orientation = trHorizontal
      Frequency = 10
      Position = 0
      SliderVisible = False
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      TickMarks = tmBottomRight
      TickStyle = tsAuto
    end
    object Kut1: TPanel
      Left = 176
      Top = 56
      Width = 25
      Height = 25
      Caption = '1'
      TabOrder = 1
    end
    object Kut2: TPanel
      Left = 208
      Top = 56
      Width = 25
      Height = 25
      Caption = '2'
      TabOrder = 2
    end
    object Kut3: TPanel
      Left = 240
      Top = 56
      Width = 25
      Height = 25
      Caption = '3'
      TabOrder = 3
    end
    object Kut4: TPanel
      Left = 272
      Top = 56
      Width = 25
      Height = 25
      Caption = '4'
      TabOrder = 4
    end
    object Kut5: TPanel
      Left = 304
      Top = 56
      Width = 25
      Height = 25
      Caption = '5'
      TabOrder = 5
    end
    object Kut6: TPanel
      Left = 336
      Top = 56
      Width = 25
      Height = 25
      Caption = '6'
      TabOrder = 6
    end
    object Kut7: TPanel
      Left = 368
      Top = 56
      Width = 25
      Height = 25
      Caption = '7'
      TabOrder = 7
    end
    object Kut8: TPanel
      Left = 400
      Top = 56
      Width = 25
      Height = 25
      Caption = '8'
      TabOrder = 8
    end
    object Kut9: TPanel
      Left = 432
      Top = 56
      Width = 25
      Height = 25
      Caption = '9'
      TabOrder = 9
    end
    object Kut10: TPanel
      Left = 464
      Top = 56
      Width = 25
      Height = 25
      Caption = '10'
      TabOrder = 10
    end
    object Kut11: TPanel
      Left = 496
      Top = 56
      Width = 25
      Height = 25
      Caption = '11'
      TabOrder = 11
    end
    object Kut12: TPanel
      Left = 528
      Top = 56
      Width = 25
      Height = 25
      Caption = '12'
      TabOrder = 12
    end
    object Kut13: TPanel
      Left = 560
      Top = 56
      Width = 25
      Height = 25
      Caption = '13'
      TabOrder = 13
    end
    object Kut14: TPanel
      Left = 592
      Top = 56
      Width = 25
      Height = 25
      Caption = '14'
      TabOrder = 14
    end
  end
  object OpenDialogIr: TOpenDialog
    DefaultExt = 'dmp'
    Filter = 'dmp|*.dmp'
    Left = 480
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'hex'
    Filter = 'hex|*.hex'
    Left = 448
  end
end
