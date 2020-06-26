object CardKonv: TCardKonv
  Left = 4
  Top = 2
  Width = 1007
  Height = 728
  Caption = 'Kártya konvertálás (txt -> crd)'
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
  object BuVezIr: TLabel
    Left = 448
    Top = 5
    Width = 129
    Height = 20
    Caption = 'Beírás BVEZ2-be'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGray
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsUnderline]
    ParentFont = False
    OnClick = BuVezIrClick
  end
  object Kijel: TLabel
    Left = 614
    Top = 90
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
  object BuMegszak: TLabel
    Left = 923
    Top = 90
    Width = 34
    Height = 20
    Caption = 'Stop'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGray
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsUnderline]
    ParentFont = False
    OnClick = BuMegszakClick
  end
  object BuVezOlv: TLabel
    Left = 8
    Top = 5
    Width = 117
    Height = 20
    Caption = 'BVEZ2 Olvasás'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGray
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsUnderline]
    ParentFont = False
    OnClick = BuVezOlvClick
  end
  object BuUjkartya: TLabel
    Left = 688
    Top = 5
    Width = 117
    Height = 20
    Caption = 'Új kártya bevitel'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsUnderline]
    ParentFont = False
    OnClick = BuUjkartyaClick
  end
  object BuDump: TLabel
    Left = 272
    Top = 5
    Width = 45
    Height = 20
    Caption = 'Dump'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGray
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsUnderline]
    ParentFont = False
    OnClick = BuDumpClick
  end
  object BuVissza: TLabel
    Left = 928
    Top = 3
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
  object GroupSor: TGroupBox
    Left = 8
    Top = 78
    Width = 313
    Height = 40
    Caption = ' Kijelölt sor kezelése'
    TabOrder = 2
    object BuSorTorol: TLabel
      Left = 248
      Top = 13
      Width = 38
      Height = 20
      Caption = 'Töröl'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = BuSorTorolClick
    end
    object BuSorHozzaad: TLabel
      Left = 16
      Top = 13
      Width = 67
      Height = 20
      Caption = 'Hozzáad'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = BuSorHozzaadClick
    end
    object BuSorBeszur: TLabel
      Left = 136
      Top = 13
      Width = 54
      Height = 20
      Caption = 'Beszúr'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = BuSorBeszurClick
    end
  end
  object CrdList: TStringGrid
    Left = 8
    Top = 120
    Width = 977
    Height = 561
    ColCount = 11
    RowCount = 2
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goRowMoving, goEditing, goTabs, goAlwaysShowEditor, goThumbTracking]
    ParentFont = False
    TabOrder = 0
    ColWidths = (
      94
      135
      46
      77
      79
      73
      66
      63
      66
      37
      226)
  end
  object GroupFile: TGroupBox
    Left = 8
    Top = 32
    Width = 593
    Height = 41
    Caption = 'File'
    TabOrder = 1
    object BuOlvas: TLabel
      Left = 16
      Top = 13
      Width = 61
      Height = 20
      Caption = 'Olvasás'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGray
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = BuOlvasClick
    end
    object NevForras: TLabel
      Left = 96
      Top = 13
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
    object BuIr: TLabel
      Left = 552
      Top = 13
      Width = 28
      Height = 20
      Caption = 'Írás'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGray
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = BuIrClick
    end
  end
  object TrackBar: TTrackBar
    Left = 608
    Top = 40
    Width = 361
    Height = 49
    Max = 100
    Orientation = trHorizontal
    Frequency = 10
    Position = 0
    SliderVisible = False
    SelEnd = 0
    SelStart = 0
    TabOrder = 3
    TabStop = False
    ThumbLength = 30
    TickMarks = tmBottomRight
    TickStyle = tsAuto
  end
  object GroupTabl: TGroupBox
    Left = 328
    Top = 78
    Width = 273
    Height = 40
    Caption = ' Táblázat kezelése'
    TabOrder = 4
    object BuEllenorzes: TLabel
      Left = 16
      Top = 13
      Width = 79
      Height = 20
      Caption = 'Ellenõrzés'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = BuEllenorzesClick
    end
    object BuTablaTorol: TLabel
      Left = 153
      Top = 13
      Width = 88
      Height = 20
      Caption = 'TáblaTörlés'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = BuTablaTorolClick
    end
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'txt'
    Filter = 'CSV text file|*.csv|TXT text file|*.txt|Card file|*.crd'
    Options = [ofEnableSizing]
    Title = 'Konvertálandó text file:'
    Left = 856
    Top = 40
  end
  object SaveDialog: TSaveDialog
    DefaultExt = '.crd'
    Filter = 'Card file|*.crd|CSV text file|*.csv'
    Title = 'Kártya file mentése'
    Left = 888
    Top = 40
  end
  object SaveDialogDump: TSaveDialog
    DefaultExt = '.dmp'
    Filter = 'Dump file|*.dmp'
    Title = 'Kártya file mentése'
    Left = 920
    Top = 40
  end
end
