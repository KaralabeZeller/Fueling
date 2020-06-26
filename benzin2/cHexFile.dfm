object HexFile: THexFile
  Left = 512
  Top = 339
  Width = 973
  Height = 723
  Caption = 'Hex File'
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
  object HexKi: TStringGrid
    Left = 8
    Top = 16
    Width = 937
    Height = 657
    ColCount = 12
    DefaultRowHeight = 16
    FixedCols = 0
    RowCount = 2
    TabOrder = 0
    ColWidths = (
      271
      34
      71
      28
      53
      64
      64
      64
      64
      64
      64
      64)
    RowHeights = (
      16
      16)
  end
end
