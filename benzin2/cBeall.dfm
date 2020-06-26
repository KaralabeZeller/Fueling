object Beallit: TBeallit
  Left = 24
  Top = 127
  Width = 349
  Height = 180
  Caption = 'Cím beállítás:'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnActivate = FormActivate
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 13
  object LabCim: TLabel
    Left = 16
    Top = 8
    Width = 35
    Height = 20
    Caption = 'Cím:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 40
    Top = 48
    Width = 24
    Height = 13
    Caption = '0= M'
  end
  object Label3: TLabel
    Left = 40
    Top = 64
    Width = 45
    Height = 13
    Caption = '2,3= Mnu'
  end
  object Label4: TLabel
    Left = 40
    Top = 80
    Width = 37
    Height = 13
    Caption = '4= Card'
  end
  object Label5: TLabel
    Left = 40
    Top = 96
    Width = 32
    Height = 13
    Caption = '6= Ora'
  end
  object Label6: TLabel
    Left = 120
    Top = 104
    Width = 89
    Height = 13
    Caption = 'x20,21-x3e,3f= Kut'
  end
  object Label7: TLabel
    Left = 40
    Top = 128
    Width = 52
    Height = 13
    Caption = '8= EEprom'
  end
  object Label8: TLabel
    Left = 120
    Top = 120
    Width = 98
    Height = 13
    Caption = 'x40,41-x5e,5f= Tank'
  end
  object Label9: TLabel
    Left = 120
    Top = 56
    Width = 48
    Height = 13
    Caption = 'x0a= NET'
  end
  object Label10: TLabel
    Left = 120
    Top = 72
    Width = 51
    Height = 13
    Caption = 'x0c= Flash'
  end
  object Label11: TLabel
    Left = 120
    Top = 88
    Width = 63
    Height = 13
    Caption = 'x0e,0f= Ceg0'
  end
  object Label12: TLabel
    Left = 40
    Top = 112
    Width = 37
    Height = 13
    Caption = '7= Arak'
  end
  object CimBe: TEdit
    Left = 200
    Top = 8
    Width = 81
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Text = 'CimBe'
  end
  object BuOk: TButton
    Left = 232
    Top = 48
    Width = 81
    Height = 25
    Caption = 'Ok'
    TabOrder = 1
    OnClick = BuOkClick
  end
  object Valaszt: TComboBox
    Left = 64
    Top = 8
    Width = 105
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 20
    ParentFont = False
    TabOrder = 2
    Text = 'RAM'
    Items.Strings = (
      'RAM'
      'FLASH')
  end
end
