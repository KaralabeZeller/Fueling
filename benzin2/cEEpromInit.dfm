object EEpromInit: TEEpromInit
  Left = 293
  Top = 4
  Width = 839
  Height = 674
  Caption = 'EEprom inicializálás beállítása'
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
  object Label1: TLabel
    Left = 24
    Top = 272
    Width = 3
    Height = 13
  end
  object BuBeir: TLabel
    Left = 240
    Top = 600
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
    Left = 456
    Top = 600
    Width = 51
    Height = 20
    Caption = 'Vissza'
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
  object BuOlvas: TLabel
    Left = 24
    Top = 600
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
    Top = 576
    Width = 16
    Height = 16
    Caption = '---'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object GroupKartyaolvaso1: TGroupBox
    Left = 648
    Top = 280
    Width = 169
    Height = 193
    Caption = ' Kártyaolvasó 1: '
    TabOrder = 0
    object CardRead1: TRadioButton
      Left = 16
      Top = 24
      Width = 145
      Height = 17
      Caption = '1 - régi(DEC-[#+10+1+3])'
      TabOrder = 0
    end
    object CardRead2: TRadioButton
      Left = 16
      Top = 48
      Width = 145
      Height = 17
      Caption = '2 - új(DEC-[#+10+1])'
      TabOrder = 1
    end
    object CardRead3: TRadioButton
      Left = 16
      Top = 72
      Width = 145
      Height = 17
      Caption = '3 - HEX[x2+08x+x3]'
      TabOrder = 2
    end
    object CardRead4: TRadioButton
      Left = 16
      Top = 96
      Width = 145
      Height = 17
      Caption = '4 - [x1+10c+x2]'
      TabOrder = 3
    end
    object CardRead5: TRadioButton
      Left = 16
      Top = 120
      Width = 145
      Height = 17
      Caption = '5 - Mifare'
      TabOrder = 4
    end
    object CardRead6: TRadioButton
      Left = 16
      Top = 144
      Width = 145
      Height = 17
      Caption = '6 - CrossPoint'
      TabOrder = 5
    end
    object CardRead7: TRadioButton
      Left = 16
      Top = 168
      Width = 145
      Height = 17
      Caption = '7 - DEC10 [#+10]'
      TabOrder = 6
    end
    object CrossPointCim: TEdit
      Left = 120
      Top = 140
      Width = 30
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 7
    end
  end
  object GroupKutfok: TGroupBox
    Left = 15
    Top = 8
    Width = 801
    Height = 73
    Caption = ' Kútfõk: '
    TabOrder = 1
    object LabOlaj: TLabel
      Left = 744
      Top = 20
      Width = 30
      Height = 13
      Caption = '0=Olaj'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabBenzin: TLabel
      Left = 744
      Top = 36
      Width = 44
      Height = 13
      Caption = '1=Benzin'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabVirtualis: TLabel
      Left = 744
      Top = 52
      Width = 48
      Height = 13
      Caption = '2=Virtuális'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Kut1: TCheckBox
      Left = 16
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be1'
      TabOrder = 0
    end
    object Kut2: TCheckBox
      Left = 64
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be2'
      TabOrder = 1
    end
    object Kut3: TCheckBox
      Left = 112
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be3'
      TabOrder = 2
    end
    object Kut4: TCheckBox
      Left = 160
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be4'
      TabOrder = 3
    end
    object Kut5: TCheckBox
      Left = 208
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be5'
      TabOrder = 4
    end
    object Kut6: TCheckBox
      Left = 256
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be6'
      TabOrder = 5
    end
    object Kut7: TCheckBox
      Left = 304
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be7'
      TabOrder = 6
    end
    object Kut8: TCheckBox
      Left = 352
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be8'
      TabOrder = 7
    end
    object BeBenzin1: TEdit
      Left = 16
      Top = 41
      Width = 25
      Height = 24
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MaxLength = 1
      ParentFont = False
      TabOrder = 8
    end
    object BeBenzin2: TEdit
      Left = 64
      Top = 41
      Width = 25
      Height = 24
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MaxLength = 1
      ParentFont = False
      TabOrder = 9
    end
    object BeBenzin4: TEdit
      Left = 160
      Top = 41
      Width = 25
      Height = 24
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MaxLength = 1
      ParentFont = False
      TabOrder = 10
    end
    object BeBenzin5: TEdit
      Left = 208
      Top = 41
      Width = 25
      Height = 24
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MaxLength = 1
      ParentFont = False
      TabOrder = 11
    end
    object BeBenzin6: TEdit
      Left = 256
      Top = 41
      Width = 25
      Height = 24
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MaxLength = 1
      ParentFont = False
      TabOrder = 12
    end
    object BeBenzin7: TEdit
      Left = 304
      Top = 41
      Width = 25
      Height = 24
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MaxLength = 1
      ParentFont = False
      TabOrder = 13
    end
    object BeBenzin8: TEdit
      Left = 352
      Top = 41
      Width = 25
      Height = 24
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MaxLength = 1
      ParentFont = False
      TabOrder = 14
    end
    object Kut9: TCheckBox
      Left = 400
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be9'
      TabOrder = 15
    end
    object Kut10: TCheckBox
      Left = 448
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be10'
      TabOrder = 16
    end
    object Kut11: TCheckBox
      Left = 496
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be11'
      TabOrder = 17
    end
    object Kut12: TCheckBox
      Left = 544
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be12'
      TabOrder = 18
    end
    object Kut13: TCheckBox
      Left = 592
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be13'
      TabOrder = 19
    end
    object Kut14: TCheckBox
      Left = 640
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be14'
      TabOrder = 20
    end
    object Kut15: TCheckBox
      Left = 688
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be15'
      TabOrder = 21
    end
    object BeBenzin9: TEdit
      Left = 400
      Top = 41
      Width = 25
      Height = 24
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MaxLength = 1
      ParentFont = False
      TabOrder = 22
    end
    object BeBenzin10: TEdit
      Left = 448
      Top = 41
      Width = 25
      Height = 24
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MaxLength = 1
      ParentFont = False
      TabOrder = 23
    end
    object BeBenzin12: TEdit
      Left = 544
      Top = 41
      Width = 25
      Height = 24
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MaxLength = 1
      ParentFont = False
      TabOrder = 24
    end
    object BeBenzin13: TEdit
      Left = 592
      Top = 41
      Width = 25
      Height = 24
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MaxLength = 1
      ParentFont = False
      TabOrder = 25
    end
    object BeBenzin14: TEdit
      Left = 640
      Top = 41
      Width = 25
      Height = 24
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MaxLength = 1
      ParentFont = False
      TabOrder = 26
    end
    object BeBenzin15: TEdit
      Left = 688
      Top = 41
      Width = 25
      Height = 24
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MaxLength = 1
      ParentFont = False
      TabOrder = 27
    end
    object BeBenzin11: TEdit
      Left = 496
      Top = 41
      Width = 25
      Height = 24
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MaxLength = 1
      ParentFont = False
      TabOrder = 28
    end
  end
  object GroupStatusz: TGroupBox
    Left = 15
    Top = 280
    Width = 305
    Height = 209
    Caption = ' Státusz beállítás: '
    TabOrder = 2
    object LabVezerloSzam: TLabel
      Left = 16
      Top = 111
      Width = 65
      Height = 13
      Caption = 'Vezérlõ szám:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabNyelv: TLabel
      Left = 16
      Top = 135
      Width = 30
      Height = 13
      Caption = 'Nyelv:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object StaLiter: TCheckBox
      Left = 16
      Top = 24
      Width = 100
      Height = 17
      Caption = 'Liter kijelzés'
      TabOrder = 0
    end
    object StaMenlev: TCheckBox
      Left = 160
      Top = 104
      Width = 120
      Height = 17
      Caption = 'Menetlevél bekérés'
      TabOrder = 1
    end
    object StaCard: TCheckBox
      Left = 16
      Top = 48
      Width = 100
      Height = 17
      Caption = '2 kártyás'
      TabOrder = 2
    end
    object StaUzem: TCheckBox
      Left = 160
      Top = 128
      Width = 120
      Height = 17
      Caption = 'Üzemóra bekérés'
      TabOrder = 3
    end
    object StaKm: TCheckBox
      Left = 160
      Top = 24
      Width = 120
      Height = 17
      Caption = 'Km bekérés'
      TabOrder = 4
      OnClick = StaKmClick
    end
    object StaKmNov: TCheckBox
      Left = 176
      Top = 48
      Width = 97
      Height = 17
      Caption = 'Km növekvõ'
      TabOrder = 5
    end
    object VezNum: TEdit
      Left = 88
      Top = 108
      Width = 41
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
    end
    object StaEkod: TCheckBox
      Left = 160
      Top = 152
      Width = 120
      Height = 17
      Caption = 'Sofõr kód bekérés'
      TabOrder = 7
    end
    object StaKmKetszer: TCheckBox
      Left = 176
      Top = 72
      Width = 97
      Height = 17
      Caption = 'Km kétszer'
      TabOrder = 8
    end
    object StaAutoStr: TCheckBox
      Left = 16
      Top = 80
      Width = 100
      Height = 17
      Caption = '1kút auto start'
      TabOrder = 9
    end
    object K4Nyelv: TComboBox
      Left = 16
      Top = 152
      Width = 113
      Height = 21
      ItemHeight = 13
      TabOrder = 10
      Text = 'Magyar'
      Items.Strings = (
        'HU-Magyar/Hungarian'
        'GB-Angol/English')
    end
    object StaMaxStop: TCheckBox
      Left = 160
      Top = 184
      Width = 120
      Height = 17
      Caption = 'MaxStop bekérés'
      TabOrder = 11
    end
  end
  object GroupKontraszt: TGroupBox
    Left = 328
    Top = 280
    Width = 193
    Height = 185
    Caption = ' Kontraszt: '
    TabOrder = 3
    object LabKontraszt: TLabel
      Left = 16
      Top = 24
      Width = 47
      Height = 13
      Caption = 'Kontraszt:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabKontKomopenz: TLabel
      Left = 16
      Top = 64
      Width = 50
      Height = 13
      Caption = 'Kompenz.:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabHoSzorzo: TLabel
      Left = 16
      Top = 104
      Width = 61
      Height = 13
      Caption = 'Hõm. szorzó:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabHoOffset: TLabel
      Left = 16
      Top = 144
      Width = 57
      Height = 13
      Caption = 'Hõm. offset:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label8: TLabel
      Left = 144
      Top = 144
      Width = 35
      Height = 13
      Caption = '(0,1 °C)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Kontraszt: TEdit
      Left = 80
      Top = 20
      Width = 57
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
    end
    object KontKomp: TEdit
      Left = 80
      Top = 60
      Width = 57
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
    end
    object Ho1Szor: TEdit
      Left = 80
      Top = 100
      Width = 57
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
    end
    object Ho1Offs: TEdit
      Left = 80
      Top = 140
      Width = 57
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
    end
  end
  object GroupNyomtatas: TGroupBox
    Left = 15
    Top = 496
    Width = 305
    Height = 65
    Caption = ' Nyomtatás: '
    TabOrder = 4
    object LabPeldanyszam: TLabel
      Left = 16
      Top = 23
      Width = 107
      Height = 13
      Caption = 'Példányszám (0,1,2,9):'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object TankDb: TEdit
      Left = 136
      Top = 20
      Width = 57
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
    end
  end
  object BeBenzin3: TEdit
    Left = 128
    Top = 49
    Width = 25
    Height = 24
    AutoSize = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    MaxLength = 1
    ParentFont = False
    TabOrder = 5
  end
  object GroupSzint1: TGroupBox
    Left = 15
    Top = 88
    Width = 801
    Height = 41
    Caption = ' 1.Szintmérõ: '
    TabOrder = 6
    object S1_1: TCheckBox
      Left = 16
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be1'
      TabOrder = 0
    end
    object S1_2: TCheckBox
      Left = 64
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be2'
      TabOrder = 1
    end
    object S1_3: TCheckBox
      Left = 112
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be3'
      TabOrder = 2
    end
    object S1_4: TCheckBox
      Left = 160
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be4'
      TabOrder = 3
    end
    object S1_5: TCheckBox
      Left = 208
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be5'
      TabOrder = 4
    end
    object S1_6: TCheckBox
      Left = 256
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be6'
      TabOrder = 5
    end
    object S1_7: TCheckBox
      Left = 304
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be7'
      TabOrder = 6
    end
    object S1_8: TCheckBox
      Left = 352
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be8'
      TabOrder = 7
    end
    object S1_9: TCheckBox
      Left = 400
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be9'
      TabOrder = 8
    end
    object S1_10: TCheckBox
      Left = 448
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be10'
      TabOrder = 9
    end
    object S1_11: TCheckBox
      Left = 496
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be11'
      TabOrder = 10
    end
    object S1_12: TCheckBox
      Left = 544
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be12'
      TabOrder = 11
    end
    object S1_13: TCheckBox
      Left = 592
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be13'
      TabOrder = 12
    end
    object S1_14: TCheckBox
      Left = 640
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be14'
      TabOrder = 13
    end
    object S1_15: TCheckBox
      Left = 688
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be15'
      TabOrder = 14
    end
    object BeSzintNum1: TEdit
      Left = 744
      Top = 9
      Width = 49
      Height = 24
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MaxLength = 5
      ParentFont = False
      TabOrder = 15
    end
  end
  object GroupSzint2: TGroupBox
    Left = 15
    Top = 136
    Width = 801
    Height = 41
    Caption = ' 2.Szintmérõ: '
    TabOrder = 7
    object BeSzintNum2: TEdit
      Left = 744
      Top = 9
      Width = 49
      Height = 24
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MaxLength = 5
      ParentFont = False
      TabOrder = 0
    end
    object S2_1: TCheckBox
      Left = 16
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be1'
      TabOrder = 1
    end
    object S2_2: TCheckBox
      Left = 64
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be2'
      TabOrder = 2
    end
    object S2_3: TCheckBox
      Left = 112
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be3'
      TabOrder = 3
    end
    object S2_4: TCheckBox
      Left = 160
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be4'
      TabOrder = 4
    end
    object S2_5: TCheckBox
      Left = 208
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be5'
      TabOrder = 5
    end
    object S2_6: TCheckBox
      Left = 256
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be6'
      TabOrder = 6
    end
    object S2_7: TCheckBox
      Left = 304
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be7'
      TabOrder = 7
    end
    object S2_8: TCheckBox
      Left = 352
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be8'
      TabOrder = 8
    end
    object S2_9: TCheckBox
      Left = 400
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be9'
      TabOrder = 9
    end
    object S2_10: TCheckBox
      Left = 448
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be10'
      TabOrder = 10
    end
    object S2_11: TCheckBox
      Left = 496
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be11'
      TabOrder = 11
    end
    object S2_12: TCheckBox
      Left = 544
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be12'
      TabOrder = 12
    end
    object S2_13: TCheckBox
      Left = 592
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be13'
      TabOrder = 13
    end
    object S2_14: TCheckBox
      Left = 640
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be14'
      TabOrder = 14
    end
    object S2_15: TCheckBox
      Left = 688
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be15'
      TabOrder = 15
    end
  end
  object GroupIdozitesek: TGroupBox
    Left = 328
    Top = 472
    Width = 313
    Height = 89
    Caption = ' Idõzítések: '
    TabOrder = 8
    object LabMnuVissza: TLabel
      Left = 16
      Top = 23
      Width = 87
      Height = 13
      Caption = 'Menü visszalépés:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabMnuVissza2: TLabel
      Left = 192
      Top = 23
      Width = 108
      Height = 13
      Caption = '(1-254s, 0v.255=nincs)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabMnuUtanvil: TLabel
      Left = 16
      Top = 55
      Width = 93
      Height = 13
      Caption = 'Menü utánvilágítás:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabMnuUtanvil2: TLabel
      Left = 192
      Top = 55
      Width = 102
      Height = 13
      Caption = '(0-254s, 255=állandó)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object BeMnuTimeout: TEdit
      Left = 128
      Top = 20
      Width = 57
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
    end
    object BeMnuUtoTime: TEdit
      Left = 128
      Top = 52
      Width = 57
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
  object GroupGyurus: TGroupBox
    Left = 528
    Top = 280
    Width = 113
    Height = 185
    Caption = ' Gyûrûs pisztoly: '
    TabOrder = 9
    object LabPisztoly1: TLabel
      Left = 16
      Top = 24
      Width = 47
      Height = 13
      Caption = 'Pisztoly 1:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabPisztoly2: TLabel
      Left = 16
      Top = 56
      Width = 47
      Height = 13
      Caption = 'Pisztoly 2:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      Visible = False
    end
    object LabPisztoly3: TLabel
      Left = 16
      Top = 88
      Width = 47
      Height = 13
      Caption = 'Pisztoly 3:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      Visible = False
    end
    object LabPistNincs: TLabel
      Left = 10
      Top = 119
      Width = 90
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '0=nincs'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabOistNum: TLabel
      Left = 10
      Top = 135
      Width = 90
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '1-14=kútfõ'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Gyurus1: TEdit
      Left = 72
      Top = 20
      Width = 30
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
    end
    object Gyurus2: TEdit
      Left = 72
      Top = 52
      Width = 30
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      Visible = False
    end
    object Gyurus3: TEdit
      Left = 72
      Top = 84
      Width = 30
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      Visible = False
    end
  end
  object GroupKartyaolvaso2: TGroupBox
    Left = 648
    Top = 480
    Width = 169
    Height = 89
    Caption = ' Kártyaolvasó 2: '
    TabOrder = 10
    object CardRead20: TRadioButton
      Left = 16
      Top = 16
      Width = 145
      Height = 17
      Caption = '0 - nincs'
      TabOrder = 0
    end
    object CardRead21: TRadioButton
      Left = 16
      Top = 40
      Width = 145
      Height = 17
      Caption = '1 - régi(DEC-[#+10+1+3])'
      TabOrder = 1
    end
    object CardRead22: TRadioButton
      Left = 16
      Top = 64
      Width = 145
      Height = 17
      Caption = '2 - WIEGAND'
      TabOrder = 2
    end
  end
  object GroupSzint3: TGroupBox
    Left = 15
    Top = 184
    Width = 801
    Height = 41
    Caption = ' 3.Szintmérõ: '
    TabOrder = 11
    object S3_1: TCheckBox
      Left = 16
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be1'
      TabOrder = 0
    end
    object S3_2: TCheckBox
      Left = 64
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be2'
      TabOrder = 1
    end
    object S3_3: TCheckBox
      Left = 112
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be3'
      TabOrder = 2
    end
    object S3_4: TCheckBox
      Left = 160
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be4'
      TabOrder = 3
    end
    object S3_5: TCheckBox
      Left = 208
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be5'
      TabOrder = 4
    end
    object S3_6: TCheckBox
      Left = 256
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be6'
      TabOrder = 5
    end
    object S3_7: TCheckBox
      Left = 304
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be7'
      TabOrder = 6
    end
    object S3_8: TCheckBox
      Left = 352
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be8'
      TabOrder = 7
    end
    object S3_9: TCheckBox
      Left = 400
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be9'
      TabOrder = 8
    end
    object S3_10: TCheckBox
      Left = 448
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be10'
      TabOrder = 9
    end
    object S3_11: TCheckBox
      Left = 496
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be11'
      TabOrder = 10
    end
    object S3_12: TCheckBox
      Left = 544
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be12'
      TabOrder = 11
    end
    object S3_13: TCheckBox
      Left = 592
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be13'
      TabOrder = 12
    end
    object S3_14: TCheckBox
      Left = 640
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be14'
      TabOrder = 13
    end
    object S3_15: TCheckBox
      Left = 688
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be15'
      TabOrder = 14
    end
  end
  object GroupSzint4: TGroupBox
    Left = 15
    Top = 232
    Width = 801
    Height = 41
    Caption = ' 4.Szintmérõ: '
    TabOrder = 12
    object S4_1: TCheckBox
      Left = 16
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be1'
      TabOrder = 0
    end
    object S4_2: TCheckBox
      Left = 64
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be2'
      TabOrder = 1
    end
    object S4_3: TCheckBox
      Left = 112
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be3'
      TabOrder = 2
    end
    object S4_4: TCheckBox
      Left = 160
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be4'
      TabOrder = 3
    end
    object S4_5: TCheckBox
      Left = 208
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be5'
      TabOrder = 4
    end
    object S4_6: TCheckBox
      Left = 256
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be6'
      TabOrder = 5
    end
    object S4_7: TCheckBox
      Left = 304
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be7'
      TabOrder = 6
    end
    object S4_8: TCheckBox
      Left = 352
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be8'
      TabOrder = 7
    end
    object S4_9: TCheckBox
      Left = 400
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be9'
      TabOrder = 8
    end
    object S4_10: TCheckBox
      Left = 448
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be10'
      TabOrder = 9
    end
    object S4_11: TCheckBox
      Left = 496
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be11'
      TabOrder = 10
    end
    object S4_12: TCheckBox
      Left = 544
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be12'
      TabOrder = 11
    end
    object S4_13: TCheckBox
      Left = 592
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be13'
      TabOrder = 12
    end
    object S4_14: TCheckBox
      Left = 640
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be14'
      TabOrder = 13
    end
    object S4_15: TCheckBox
      Left = 688
      Top = 16
      Width = 50
      Height = 17
      Caption = 'Be15'
      TabOrder = 14
    end
  end
end
