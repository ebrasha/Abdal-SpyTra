//---------------------------------------------------------------------------

#ifndef ASVPH
#define ASVPH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "ipwipdaemon.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TipwIPDaemon *IPD;
	TTimer *hpagetimer;
	void __fastcall IPDConnected(TObject *Sender, TipwIPDaemonConnectedEventParams *e);
	void __fastcall IPDDataIn(TObject *Sender, TipwIPDaemonDataInEventParams *e);
	void __fastcall IPDConnectionRequest(TObject *Sender, TipwIPDaemonConnectionRequestEventParams *e);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall hpagetimerTimer(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
