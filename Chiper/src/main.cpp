#include<iostream>
#include <main.hpp>
using namespace std;

int main(int argc,char ** argv){
	string message = "Bgc-bfufb tegaedppqna ql aggv zge xof tegaedppfe'l lgjb.\n"
					"Xof adpf vflqanfe logjbvn'x hf pdwqna d cgebv qn coqro xof tbdkfe ql mjlx d lpdbb tdex. Xof tbdkfe QL XOF HGLL; qx'l kgje vjxk xg fnxfexdqn oqp ge ofe.\n"
					"Zgrjl ql d pdxxfe gz vfrqvqna codx xoqnal kgj def ngx agqna xg vg.\n"
					"Xof rglx gz dvvqna d zfdxjef qln'x mjlx xof xqpf qx xdwfl xg rgvf qx. Xof rglx dblg qnrbjvfl xof dvvqxqgn gz dn ghlxdrbf xg zjxjef fstdnlqgn. Xof xeqrw ql xg tqrw xof zfdxjefl xodx vgn'x zqaox fdro gxofe. - Mgon Rdepdrw.\n"
					"(ccc.adpdljxed.rgp/uqfc/nfcl/234346?utkjpvbjr)\n"
					"(ccc.hedqnkijgxf.rgp/ijgxfl/djxogel/m/mgon_rdepdrw.oxpb)\n";
	string freqLang = "TEOAISRHNUCMDLGWFPYKJBVQX";
	string original = decryptMessage(message, freqLang);
	cout<<original;
	return 0;
}