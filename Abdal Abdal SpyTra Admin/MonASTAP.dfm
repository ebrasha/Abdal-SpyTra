object MonASTA: TMonASTA
  Left = 0
  Top = 0
  Caption = 'Attack Monitoring -  Attack Result : (received from Victim)'
  ClientHeight = 447
  ClientWidth = 775
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object mon: TListBox
    Left = 0
    Top = 0
    Width = 775
    Height = 447
    TabStop = False
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    MultiSelect = True
    ParentFont = False
    TabOrder = 0
  end
end
