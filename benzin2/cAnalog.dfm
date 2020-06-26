object Analog: TAnalog
  Left = 59
  Top = 103
  Width = 710
  Height = 379
  Caption = 'Analóg mérések'
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
  object UzenKiolv: TLabel
    Left = 96
    Top = 8
    Width = 39
    Height = 20
    Caption = 'Uzen'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object GroupTapfesz: TGroupBox
    Left = 352
    Top = 5
    Width = 329
    Height = 98
    Caption = ' Tápfeszültségek: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object KiU11: TLabel
      Left = 64
      Top = 32
      Width = 24
      Height = 20
      Caption = '0 V'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabU11: TLabel
      Left = 16
      Top = 32
      Width = 35
      Height = 20
      Caption = 'U11:'
    end
    object LabU10: TLabel
      Left = 16
      Top = 64
      Width = 35
      Height = 20
      Caption = 'U10:'
    end
    object KiU10: TLabel
      Left = 64
      Top = 64
      Width = 24
      Height = 20
      Caption = '0 V'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object UzenTap: TLabel
      Left = 128
      Top = 64
      Width = 67
      Height = 20
      Caption = 'UzenTap'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object BeU11: TEdit
      Left = 128
      Top = 30
      Width = 57
      Height = 28
      TabOrder = 0
      Text = '150'
    end
    object BuBeirU11: TButton
      Left = 248
      Top = 64
      Width = 75
      Height = 25
      Caption = 'BeirU11'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = BuBeirU11Click
    end
  end
  object GroupMa1: TGroupBox
    Left = 8
    Top = 109
    Width = 329
    Height = 108
    Caption = ' 4..20mA 1-es bemenet: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object KiMa1: TLabel
      Left = 32
      Top = 40
      Width = 65
      Height = 20
      Caption = '00000uA'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object UzenMa1: TLabel
      Left = 128
      Top = 72
      Width = 39
      Height = 20
      Caption = 'Uzen'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabSzorzo1: TLabel
      Left = 128
      Top = 20
      Width = 44
      Height = 16
      Caption = 'Szorzó:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabNulla1: TLabel
      Left = 208
      Top = 20
      Width = 34
      Height = 16
      Caption = 'Nulla:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object BeSzorMa1: TEdit
      Left = 128
      Top = 38
      Width = 57
      Height = 28
      TabOrder = 0
      Text = '15000'
    end
    object BuBeirMa1: TButton
      Left = 248
      Top = 72
      Width = 75
      Height = 25
      Caption = 'BeirMa1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = BuBeirMa1Click
    end
    object BeNullMa1: TEdit
      Left = 208
      Top = 38
      Width = 57
      Height = 28
      TabOrder = 2
      Text = '15000'
    end
  end
  object BuKiolv: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Kiolv'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = BuKiolvClick
  end
  object GroupMa2: TGroupBox
    Left = 8
    Top = 221
    Width = 329
    Height = 108
    Caption = ' 4..20mA 2-es bemenet: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    object KiMa2: TLabel
      Left = 32
      Top = 40
      Width = 65
      Height = 20
      Caption = '00000uA'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object UzenMa2: TLabel
      Left = 128
      Top = 72
      Width = 39
      Height = 20
      Caption = 'Uzen'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabSzorzo2: TLabel
      Left = 128
      Top = 20
      Width = 44
      Height = 16
      Caption = 'Szorzó:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabNulla2: TLabel
      Left = 208
      Top = 20
      Width = 34
      Height = 16
      Caption = 'Nulla:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object BeSzorMa2: TEdit
      Left = 128
      Top = 38
      Width = 57
      Height = 28
      TabOrder = 0
      Text = '15000'
    end
    object BuBeirMa2: TButton
      Left = 248
      Top = 72
      Width = 75
      Height = 25
      Caption = 'BeirMa2'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = BuBeirMa2Click
    end
    object BeNullMa2: TEdit
      Left = 208
      Top = 38
      Width = 57
      Height = 28
      TabOrder = 2
      Text = '15000'
    end
  end
  object GroupMa3: TGroupBox
    Left = 352
    Top = 109
    Width = 329
    Height = 108
    Caption = ' 4..20mA 3-as bemenet: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    object KiMa3: TLabel
      Left = 32
      Top = 40
      Width = 65
      Height = 20
      Caption = '00000uA'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object UzenMa3: TLabel
      Left = 128
      Top = 72
      Width = 39
      Height = 20
      Caption = 'Uzen'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabSzorzo3: TLabel
      Left = 128
      Top = 20
      Width = 44
      Height = 16
      Caption = 'Szorzó:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabNulla3: TLabel
      Left = 208
      Top = 20
      Width = 34
      Height = 16
      Caption = 'Nulla:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object BeSzorMa3: TEdit
      Left = 128
      Top = 38
      Width = 57
      Height = 28
      TabOrder = 0
      Text = '15000'
    end
    object BuBeirMa3: TButton
      Left = 248
      Top = 72
      Width = 75
      Height = 25
      Caption = 'BeirMa3'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = BuBeirMa3Click
    end
    object BeNullMa3: TEdit
      Left = 208
      Top = 38
      Width = 57
      Height = 28
      TabOrder = 2
      Text = '15000'
    end
  end
  object GroupMa4: TGroupBox
    Left = 352
    Top = 221
    Width = 329
    Height = 108
    Caption = ' 4..20mA 4-es bemenet: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    object KiMa4: TLabel
      Left = 32
      Top = 40
      Width = 65
      Height = 20
      Caption = '00000uA'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object UzenMa4: TLabel
      Left = 128
      Top = 72
      Width = 39
      Height = 20
      Caption = 'Uzen'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabSzorzo4: TLabel
      Left = 128
      Top = 20
      Width = 44
      Height = 16
      Caption = 'Szorzó:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabNulla4: TLabel
      Left = 208
      Top = 20
      Width = 34
      Height = 16
      Caption = 'Nulla:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object BeSzorMa4: TEdit
      Left = 128
      Top = 38
      Width = 57
      Height = 28
      TabOrder = 0
      Text = '15000'
    end
    object BuBeirMa4: TButton
      Left = 248
      Top = 72
      Width = 75
      Height = 25
      Caption = 'BeirMa4'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = BuBeirMa4Click
    end
    object BeNullMa4: TEdit
      Left = 208
      Top = 38
      Width = 57
      Height = 28
      TabOrder = 2
      Text = '15000'
    end
  end
end
