// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ASTAP.h"
#include "MonASTAP.h"
// ---------------------------------------------------------------------------
#pragma link "ipwipport"
#pragma link "acPNG"
#pragma resource "*.dfm"
TFormEchoclientf *FormEchoclientf;
unsigned long gStartTime;
bool bError;

// ---------------------------------------------------------------------------
__fastcall TFormEchoclientf::TFormEchoclientf(TComponent* Owner) : TForm(Owner)
{
}

// ---------------------------------------------------------------------------
void __fastcall TFormEchoclientf::bConnectClick(TObject *Sender) {
	MonASTA->mon->Clear();
	bEcho->Enabled = FALSE;
	try {
		IPPort1->EOL = "\n";

		if (IPPort1->RemoteHost != tHost->Text) {
			IPPort1->Connected = FALSE;
			// unconditionally break the old connection
			IPPort1->RemoteHost = tHost->Text;
		}

		IPPort1->RemotePort = StrToInt(EditPort->Text); // TCP echo service
		IPPort1->Connected = TRUE;
		ListStatus->Items->Add("Connecting to " + IPPort1->RemoteHost);

		bError = FALSE;
		unsigned long after15Seconds = GetTickCount() + 15 * 1000;
		while (GetTickCount() < after15Seconds) {
			if (IPPort1->Connected || bError)
				break;
			Application->ProcessMessages();
		}

		if (IPPort1->Connected) {
			bEcho->Enabled = TRUE;
			CommandBox->SetFocus();
		}
		else {
			IPPort1->Connected = FALSE;
			// forcely break any connection in cource
			ListStatus->Items->Add("Timed out ");
		}

	}
	catch (EIPWCore& exception) {
		ListStatus->Items->Add("Exception: " + exception.Message);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFormEchoclientf::FormDestroy(TObject *Sender) {
	IPPort1->Connected = FALSE;
}

// ---------------------------------------------------------------------------
void __fastcall TFormEchoclientf::DisconnectClick(TObject *Sender) {
	IPPort1->Connected = FALSE;
}

// ---------------------------------------------------------------------------

void __fastcall TFormEchoclientf::IPPort1DataIn(TObject *Sender,
	TipwIPPortDataInEventParams *e) {
	char time[10];
	unsigned long t = GetTickCount() - gStartTime;
	ultoa(t, time, 10);

	MonASTA->mon->Items->Add(AnsiString(e->Text) + "   Running Time : " + time +
		" milliseconds");
	MonASTA->mon->Items->Add("---------------------------------------");
}
// ---------------------------------------------------------------------------

void __fastcall TFormEchoclientf::IPPort1Connected(TObject *Sender,
	TipwIPPortConnectedEventParams *e) {
	if (e->StatusCode) {
		MonASTA->mon->Items->Add("Connection failed: " + e->Description);
		bError = TRUE;
	}
	else
		ListStatus->Items->Add("Connected: " + e->Description);
}
// ---------------------------------------------------------------------------

void __fastcall TFormEchoclientf::IPPort1Disconnected(TObject *Sender,
	TipwIPPortDisconnectedEventParams *e) {
	ListStatus->Items->Add("Disconnected");
}
// ---------------------------------------------------------------------------

void __fastcall TFormEchoclientf::bEchoClick(TObject *Sender) {
	// notice the time
	gStartTime = GetTickCount();

	// send anything and the server will send the time
	IPPort1->DataToSend = CommandBox->Text;

	CommandBox->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TFormEchoclientf::MonBTClick(TObject *Sender)
{
	MonASTA->Show();
}
//---------------------------------------------------------------------------

