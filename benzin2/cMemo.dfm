object PrgMem: TPrgMem
  Left = 112
  Top = 9
  Width = 1169
  Height = 755
  Caption = 'Program memória'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poDesktopCenter
  OnActivate = FormActivate
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 13
  object MemKi: TStringGrid
    Left = 8
    Top = 32
    Width = 1129
    Height = 657
    ColCount = 17
    DefaultRowHeight = 16
    RowCount = 2753
    TabOrder = 0
  end
end
