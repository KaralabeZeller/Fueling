object FlsClr: TFlsClr
  Left = 40
  Top = 29
  Width = 562
  Height = 407
  Caption = 'Flash Clear'
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
  object LabVigyazz: TLabel
    Left = 8
    Top = 8
    Width = 529
    Height = 24
    Alignment = taCenter
    AutoSize = False
    Caption = 'VIGYÁZZ TÖRÖLSZ!!!'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object BuVissza: TLabel
    Left = 480
    Top = 333
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
  object BuStop: TLabel
    Left = 240
    Top = 333
    Width = 34
    Height = 20
    Caption = 'Stop'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsUnderline]
    ParentFont = False
    OnClick = BuStopClick
  end
  object GroupKartyak: TGroupBox
    Left = 8
    Top = 104
    Width = 529
    Height = 65
    Caption = ' Kártyák '
    TabOrder = 0
    object KiKartya: TLabel
      Left = 64
      Top = 37
      Width = 393
      Height = 20
      Alignment = taCenter
      AutoSize = False
      Caption = '---'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object BuOlvasCrd: TLabel
      Left = 8
      Top = 37
      Width = 43
      Height = 20
      Caption = 'Olvas'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = BuOlvasCrdClick
    end
    object BuTorolCrd: TLabel
      Left = 472
      Top = 37
      Width = 47
      Height = 20
      Caption = 'Törlés'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = BuTorolCrdClick
    end
    object Kartyak: TControlBar
      Left = 8
      Top = 16
      Width = 512
      Height = 20
      BevelInner = bvLowered
      TabOrder = 0
      OnPaint = KartyakPaint
    end
  end
  object GroupCegek: TGroupBox
    Left = 8
    Top = 248
    Width = 529
    Height = 65
    Caption = ' Cégek '
    TabOrder = 1
    object KiCeg: TLabel
      Left = 64
      Top = 37
      Width = 401
      Height = 20
      Alignment = taCenter
      AutoSize = False
      Caption = '---'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object BuOlvasCeg: TLabel
      Left = 8
      Top = 37
      Width = 43
      Height = 20
      Caption = 'Olvas'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = BuOlvasCegClick
    end
    object BuTorolCeg: TLabel
      Left = 472
      Top = 37
      Width = 47
      Height = 20
      Caption = 'Törlés'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = BuTorolCegClick
    end
    object Cegek: TControlBar
      Left = 8
      Top = 16
      Width = 512
      Height = 20
      BevelInner = bvLowered
      TabOrder = 0
      OnPaint = KartyakPaint
    end
  end
  object GroupTankolasok: TGroupBox
    Left = 8
    Top = 32
    Width = 529
    Height = 65
    Caption = ' Tankolások '
    TabOrder = 2
    object KiTank: TLabel
      Left = 64
      Top = 37
      Width = 393
      Height = 20
      Alignment = taCenter
      AutoSize = False
      Caption = '---'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object BuOlvasTank: TLabel
      Left = 8
      Top = 37
      Width = 43
      Height = 20
      Caption = 'Olvas'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = BuOlvasTankClick
    end
    object BuTorolTank: TLabel
      Left = 472
      Top = 37
      Width = 47
      Height = 20
      Caption = 'Törlés'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = BuTorolTankClick
    end
    object Tankok: TControlBar
      Left = 8
      Top = 16
      Width = 512
      Height = 20
      BevelInner = bvLowered
      TabOrder = 0
      OnPaint = KartyakPaint
    end
  end
  object GroupArak: TGroupBox
    Left = 8
    Top = 176
    Width = 529
    Height = 65
    Caption = ' Árak '
    TabOrder = 3
    object KiArak: TLabel
      Left = 64
      Top = 37
      Width = 401
      Height = 20
      Alignment = taCenter
      AutoSize = False
      Caption = '---'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object BuOlvasArak: TLabel
      Left = 8
      Top = 37
      Width = 43
      Height = 20
      Caption = 'Olvas'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = BuOlvasArakClick
    end
    object BuTorolArak: TLabel
      Left = 472
      Top = 37
      Width = 47
      Height = 20
      Caption = 'Törlés'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = BuTorolArakClick
    end
    object Arak: TControlBar
      Left = 8
      Top = 16
      Width = 512
      Height = 20
      BevelInner = bvLowered
      TabOrder = 0
      OnPaint = KartyakPaint
    end
  end
end
