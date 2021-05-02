// ---------------------------------------------------------------------------
#ifndef ASTAPH
#define ASTAPH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ipwipport.h"
#include <ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>

// ---------------------------------------------------------------------------
class TFormEchoclientf : public TForm {
__published: // IDE-managed Components
	TipwIPPort *IPPort1;
	TGroupBox *GroupBoxStatus;
	TListBox *ListStatus;
	TButton *bEcho;
	TButton *bConnect;
	TButton *Disconnect;
	TEdit *EditPort;
	TEdit *tHost;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label4;
	TImage *Image1;
	TEdit *CommandBox;
	TLabel *Label3;
	TButton *MonBT;

	void __fastcall bConnectClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall DisconnectClick(TObject *Sender);
	void __fastcall IPPort1DataIn(TObject *Sender,
		TipwIPPortDataInEventParams *e);
	void __fastcall IPPort1Connected(TObject *Sender,
		TipwIPPortConnectedEventParams *e);
	void __fastcall IPPort1Disconnected(TObject *Sender,
		TipwIPPortDisconnectedEventParams *e);
	void __fastcall bEchoClick(TObject *Sender);
	void __fastcall MonBTClick(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TFormEchoclientf(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern TFormEchoclientf *FormEchoclientf;
// ---------------------------------------------------------------------------
#endif
