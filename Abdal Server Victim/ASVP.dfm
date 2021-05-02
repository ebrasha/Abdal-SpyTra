object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'svchost'
  ClientHeight = 202
  ClientWidth = 447
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object IPD: TipwIPDaemon
    OnConnected = IPDConnected
    OnConnectionRequest = IPDConnectionRequest
    OnDataIn = IPDDataIn
    Left = 376
    Top = 8
  end
  object hpagetimer: TTimer
    Enabled = False
    Interval = 4000
    OnTimer = hpagetimerTimer
    Left = 216
    Top = 104
  end
end
