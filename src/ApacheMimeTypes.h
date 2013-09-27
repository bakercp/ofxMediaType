// =============================================================================
//
// Copyright (c) 2009-2013 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#pragma once


#include <iostream>
#include <map>
#include <string>
#include "Poco/Net/MediaType.h"


namespace ofx {
namespace Media {


static std::string apacheMimeTypes = "" \
"# http://svn.apache.org/viewvc/httpd/httpd/trunk/docs/conf/mime.types?view=markup\n" \
"#\n" \
"#\n" \
"# This file maps Internet media types to unique file extension(s).\n" \
"# Although created for httpd, this file is used by many software systems\n" \
"# and has been placed in the public domain for unlimited redisribution.\n" \
"#\n" \
"# The table below contains both registered and (common) unregistered types.\n" \
"# A type that has no unique extension can be ignored -- they are listed\n" \
"# here to guide configurations toward known types and to make it easier to\n" \
"# identify \"new\" types.  File extensions are also commonly used to indicate\n" \
"# content languages and encodings, so choose them carefully.\n" \
"#\n" \
"# Internet media types should be registered as described in RFC 4288.\n" \
"# The registry is at <http://www.iana.org/assignments/media-types/>.\n" \
"#\n" \
"# MIME type (lowercased)			Extensions\n" \
"# ============================================	==========\n" \
"# application/1d-interleaved-parityfec\n" \
"# application/3gpp-ims+xml\n" \
"# application/activemessage\n" \
"application/andrew-inset			ez\n" \
"# application/applefile\n" \
"application/applixware				aw\n" \
"application/atom+xml				atom\n" \
"application/atomcat+xml				atomcat\n" \
"# application/atomicmail\n" \
"application/atomsvc+xml				atomsvc\n" \
"# application/auth-policy+xml\n" \
"# application/batch-smtp\n" \
"# application/beep+xml\n" \
"# application/calendar+xml\n" \
"# application/cals-1840\n" \
"# application/ccmp+xml\n" \
"application/ccxml+xml				ccxml\n" \
"application/cdmi-capability			cdmia\n" \
"application/cdmi-container			cdmic\n" \
"application/cdmi-domain				cdmid\n" \
"application/cdmi-object				cdmio\n" \
"application/cdmi-queue				cdmiq\n" \
"# application/cea-2018+xml\n" \
"# application/cellml+xml\n" \
"# application/cfw\n" \
"# application/cnrp+xml\n" \
"# application/commonground\n" \
"# application/conference-info+xml\n" \
"# application/cpl+xml\n" \
"# application/csta+xml\n" \
"# application/cstadata+xml\n" \
"application/cu-seeme				cu\n" \
"# application/cybercash\n" \
"application/davmount+xml			davmount\n" \
"# application/dca-rft\n" \
"# application/dec-dx\n" \
"# application/dialog-info+xml\n" \
"# application/dicom\n" \
"# application/dns\n" \
"application/docbook+xml				dbk\n" \
"# application/dskpp+xml\n" \
"application/dssc+der				dssc\n" \
"application/dssc+xml				xdssc\n" \
"# application/dvcs\n" \
"application/ecmascript				ecma\n" \
"# application/edi-consent\n" \
"# application/edi-x12\n" \
"# application/edifact\n" \
"application/emma+xml				emma\n" \
"# application/epp+xml\n" \
"application/epub+zip				epub\n" \
"# application/eshop\n" \
"# application/example\n" \
"application/exi					exi\n" \
"# application/fastinfoset\n" \
"# application/fastsoap\n" \
"# application/fits\n" \
"application/font-tdpfr				pfr\n" \
"# application/framework-attributes+xml\n" \
"application/gml+xml				gml\n" \
"application/gpx+xml				gpx\n" \
"application/gxf					gxf\n" \
"# application/h224\n" \
"# application/held+xml\n" \
"# application/http\n" \
"application/hyperstudio				stk\n" \
"# application/ibe-key-request+xml\n" \
"# application/ibe-pkg-reply+xml\n" \
"# application/ibe-pp-data\n" \
"# application/iges\n" \
"# application/im-iscomposing+xml\n" \
"# application/index\n" \
"# application/index.cmd\n" \
"# application/index.obj\n" \
"# application/index.response\n" \
"# application/index.vnd\n" \
"application/inkml+xml				ink inkml\n" \
"# application/iotp\n" \
"application/ipfix				ipfix\n" \
"# application/ipp\n" \
"# application/isup\n" \
"application/java-archive			jar\n" \
"application/java-serialized-object		ser\n" \
"application/java-vm				class\n" \
"application/javascript				js\n" \
"application/json				json\n" \
"application/jsonml+json				jsonml\n" \
"# application/kpml-request+xml\n" \
"# application/kpml-response+xml\n" \
"application/lost+xml				lostxml\n" \
"application/mac-binhex40			hqx\n" \
"application/mac-compactpro			cpt\n" \
"# application/macwriteii\n" \
"application/mads+xml				mads\n" \
"application/marc				mrc\n" \
"application/marcxml+xml				mrcx\n" \
"application/mathematica				ma nb mb\n" \
"# application/mathml-content+xml\n" \
"# application/mathml-presentation+xml\n" \
"application/mathml+xml				mathml\n" \
"# application/mbms-associated-procedure-description+xml\n" \
"# application/mbms-deregister+xml\n" \
"# application/mbms-envelope+xml\n" \
"# application/mbms-msk+xml\n" \
"# application/mbms-msk-response+xml\n" \
"# application/mbms-protection-description+xml\n" \
"# application/mbms-reception-report+xml\n" \
"# application/mbms-register+xml\n" \
"# application/mbms-register-response+xml\n" \
"# application/mbms-user-service-description+xml\n" \
"application/mbox				mbox\n" \
"# application/media_control+xml\n" \
"application/mediaservercontrol+xml		mscml\n" \
"application/metalink+xml			metalink\n" \
"application/metalink4+xml			meta4\n" \
"application/mets+xml				mets\n" \
"# application/mikey\n" \
"application/mods+xml				mods\n" \
"# application/moss-keys\n" \
"# application/moss-signature\n" \
"# application/mosskey-data\n" \
"# application/mosskey-request\n" \
"application/mp21				m21 mp21\n" \
"application/mp4					mp4s\n" \
"# application/mpeg4-generic\n" \
"# application/mpeg4-iod\n" \
"# application/mpeg4-iod-xmt\n" \
"# application/msc-ivr+xml\n" \
"# application/msc-mixer+xml\n" \
"application/msword				doc dot\n" \
"application/mxf					mxf\n" \
"# application/nasdata\n" \
"# application/news-checkgroups\n" \
"# application/news-groupinfo\n" \
"# application/news-transmission\n" \
"# application/nss\n" \
"# application/ocsp-request\n" \
"# application/ocsp-response\n" \
"application/octet-stream	bin dms lrf mar so dist distz pkg bpk dump elc deploy\n" \
"application/oda					oda\n" \
"application/oebps-package+xml			opf\n" \
"application/ogg					ogx\n" \
"application/omdoc+xml				omdoc\n" \
"application/onenote				onetoc onetoc2 onetmp onepkg\n" \
"application/oxps				oxps\n" \
"# application/parityfec\n" \
"application/patch-ops-error+xml			xer\n" \
"application/pdf					pdf\n" \
"application/pgp-encrypted			pgp\n" \
"# application/pgp-keys\n" \
"application/pgp-signature			asc sig\n" \
"application/pics-rules				prf\n" \
"# application/pidf+xml\n" \
"# application/pidf-diff+xml\n" \
"application/pkcs10				p10\n" \
"application/pkcs7-mime				p7m p7c\n" \
"application/pkcs7-signature			p7s\n" \
"application/pkcs8				p8\n" \
"application/pkix-attr-cert			ac\n" \
"application/pkix-cert				cer\n" \
"application/pkix-crl				crl\n" \
"application/pkix-pkipath			pkipath\n" \
"application/pkixcmp				pki\n" \
"application/pls+xml				pls\n" \
"# application/poc-settings+xml\n" \
"application/postscript				ai eps ps\n" \
"# application/prs.alvestrand.titrax-sheet\n" \
"application/prs.cww				cww\n" \
"# application/prs.nprend\n" \
"# application/prs.plucker\n" \
"# application/prs.rdf-xml-crypt\n" \
"# application/prs.xsf+xml\n" \
"application/pskc+xml				pskcxml\n" \
"# application/qsig\n" \
"application/rdf+xml				rdf\n" \
"application/reginfo+xml				rif\n" \
"application/relax-ng-compact-syntax		rnc\n" \
"# application/remote-printing\n" \
"application/resource-lists+xml			rl\n" \
"application/resource-lists-diff+xml		rld\n" \
"# application/riscos\n" \
"# application/rlmi+xml\n" \
"application/rls-services+xml			rs\n" \
"application/rpki-ghostbusters			gbr\n" \
"application/rpki-manifest			mft\n" \
"application/rpki-roa				roa\n" \
"# application/rpki-updown\n" \
"application/rsd+xml				rsd\n" \
"application/rss+xml				rss\n" \
"application/rtf					rtf\n" \
"# application/rtx\n" \
"# application/samlassertion+xml\n" \
"# application/samlmetadata+xml\n" \
"application/sbml+xml				sbml\n" \
"application/scvp-cv-request			scq\n" \
"application/scvp-cv-response			scs\n" \
"application/scvp-vp-request			spq\n" \
"application/scvp-vp-response			spp\n" \
"application/sdp					sdp\n" \
"# application/set-payment\n" \
"application/set-payment-initiation		setpay\n" \
"# application/set-registration\n" \
"application/set-registration-initiation		setreg\n" \
"# application/sgml\n" \
"# application/sgml-open-catalog\n" \
"application/shf+xml				shf\n" \
"# application/sieve\n" \
"# application/simple-filter+xml\n" \
"# application/simple-message-summary\n" \
"# application/simplesymbolcontainer\n" \
"# application/slate\n" \
"# application/smil\n" \
"application/smil+xml				smi smil\n" \
"# application/soap+fastinfoset\n" \
"# application/soap+xml\n" \
"application/sparql-query			rq\n" \
"application/sparql-results+xml			srx\n" \
"# application/spirits-event+xml\n" \
"application/srgs				gram\n" \
"application/srgs+xml				grxml\n" \
"application/sru+xml				sru\n" \
"application/ssdl+xml				ssdl\n" \
"application/ssml+xml				ssml\n" \
"# application/tamp-apex-update\n" \
"# application/tamp-apex-update-confirm\n" \
"# application/tamp-community-update\n" \
"# application/tamp-community-update-confirm\n" \
"# application/tamp-error\n" \
"# application/tamp-sequence-adjust\n" \
"# application/tamp-sequence-adjust-confirm\n" \
"# application/tamp-status-query\n" \
"# application/tamp-status-response\n" \
"# application/tamp-update\n" \
"# application/tamp-update-confirm\n" \
"application/tei+xml				tei teicorpus\n" \
"application/thraud+xml				tfi\n" \
"# application/timestamp-query\n" \
"# application/timestamp-reply\n" \
"application/timestamped-data			tsd\n" \
"# application/tve-trigger\n" \
"# application/ulpfec\n" \
"# application/vcard+xml\n" \
"# application/vemmi\n" \
"# application/vividence.scriptfile\n" \
"# application/vnd.3gpp.bsf+xml\n" \
"application/vnd.3gpp.pic-bw-large		plb\n" \
"application/vnd.3gpp.pic-bw-small		psb\n" \
"application/vnd.3gpp.pic-bw-var			pvb\n" \
"# application/vnd.3gpp.sms\n" \
"# application/vnd.3gpp2.bcmcsinfo+xml\n" \
"# application/vnd.3gpp2.sms\n" \
"application/vnd.3gpp2.tcap			tcap\n" \
"application/vnd.3m.post-it-notes		pwn\n" \
"application/vnd.accpac.simply.aso		aso\n" \
"application/vnd.accpac.simply.imp		imp\n" \
"application/vnd.acucobol			acu\n" \
"application/vnd.acucorp				atc acutc\n" \
"application/vnd.adobe.air-application-installer-package+zip	air\n" \
"application/vnd.adobe.formscentral.fcdt		fcdt\n" \
"application/vnd.adobe.fxp			fxp fxpl\n" \
"# application/vnd.adobe.partial-upload\n" \
"application/vnd.adobe.xdp+xml			xdp\n" \
"application/vnd.adobe.xfdf			xfdf\n" \
"# application/vnd.aether.imp\n" \
"# application/vnd.ah-barcode\n" \
"application/vnd.ahead.space			ahead\n" \
"application/vnd.airzip.filesecure.azf		azf\n" \
"application/vnd.airzip.filesecure.azs		azs\n" \
"application/vnd.amazon.ebook			azw\n" \
"application/vnd.americandynamics.acc		acc\n" \
"application/vnd.amiga.ami			ami\n" \
"# application/vnd.amundsen.maze+xml\n" \
"application/vnd.android.package-archive		apk\n" \
"application/vnd.anser-web-certificate-issue-initiation	cii\n" \
"application/vnd.anser-web-funds-transfer-initiation	fti\n" \
"application/vnd.antix.game-component		atx\n" \
"application/vnd.apple.installer+xml		mpkg\n" \
"application/vnd.apple.mpegurl			m3u8\n" \
"# application/vnd.arastra.swi\n" \
"application/vnd.aristanetworks.swi		swi\n" \
"application/vnd.astraea-software.iota		iota\n" \
"application/vnd.audiograph			aep\n" \
"# application/vnd.autopackage\n" \
"# application/vnd.avistar+xml\n" \
"application/vnd.blueice.multipass		mpm\n" \
"# application/vnd.bluetooth.ep.oob\n" \
"application/vnd.bmi				bmi\n" \
"application/vnd.businessobjects			rep\n" \
"# application/vnd.cab-jscript\n" \
"# application/vnd.canon-cpdl\n" \
"# application/vnd.canon-lips\n" \
"# application/vnd.cendio.thinlinc.clientconf\n" \
"application/vnd.chemdraw+xml			cdxml\n" \
"application/vnd.chipnuts.karaoke-mmd		mmd\n" \
"application/vnd.cinderella			cdy\n" \
"# application/vnd.cirpack.isdn-ext\n" \
"application/vnd.claymore			cla\n" \
"application/vnd.cloanto.rp9			rp9\n" \
"application/vnd.clonk.c4group			c4g c4d c4f c4p c4u\n" \
"application/vnd.cluetrust.cartomobile-config		c11amc\n" \
"application/vnd.cluetrust.cartomobile-config-pkg	c11amz\n" \
"# application/vnd.collection+json\n" \
"# application/vnd.commerce-battelle\n" \
"application/vnd.commonspace			csp\n" \
"application/vnd.contact.cmsg			cdbcmsg\n" \
"application/vnd.cosmocaller			cmc\n" \
"application/vnd.crick.clicker			clkx\n" \
"application/vnd.crick.clicker.keyboard		clkk\n" \
"application/vnd.crick.clicker.palette		clkp\n" \
"application/vnd.crick.clicker.template		clkt\n" \
"application/vnd.crick.clicker.wordbank		clkw\n" \
"application/vnd.criticaltools.wbs+xml		wbs\n" \
"application/vnd.ctc-posml			pml\n" \
"# application/vnd.ctct.ws+xml\n" \
"# application/vnd.cups-pdf\n" \
"# application/vnd.cups-postscript\n" \
"application/vnd.cups-ppd			ppd\n" \
"# application/vnd.cups-raster\n" \
"# application/vnd.cups-raw\n" \
"# application/vnd.curl\n" \
"application/vnd.curl.car			car\n" \
"application/vnd.curl.pcurl			pcurl\n" \
"# application/vnd.cybank\n" \
"application/vnd.dart				dart\n" \
"application/vnd.data-vision.rdz			rdz\n" \
"application/vnd.dece.data			uvf uvvf uvd uvvd\n" \
"application/vnd.dece.ttml+xml			uvt uvvt\n" \
"application/vnd.dece.unspecified		uvx uvvx\n" \
"application/vnd.dece.zip			uvz uvvz\n" \
"application/vnd.denovo.fcselayout-link		fe_launch\n" \
"# application/vnd.dir-bi.plate-dl-nosuffix\n" \
"application/vnd.dna				dna\n" \
"application/vnd.dolby.mlp			mlp\n" \
"# application/vnd.dolby.mobile.1\n" \
"# application/vnd.dolby.mobile.2\n" \
"application/vnd.dpgraph				dpg\n" \
"application/vnd.dreamfactory			dfac\n" \
"application/vnd.ds-keypoint			kpxx\n" \
"application/vnd.dvb.ait				ait\n" \
"# application/vnd.dvb.dvbj\n" \
"# application/vnd.dvb.esgcontainer\n" \
"# application/vnd.dvb.ipdcdftnotifaccess\n" \
"# application/vnd.dvb.ipdcesgaccess\n" \
"# application/vnd.dvb.ipdcesgaccess2\n" \
"# application/vnd.dvb.ipdcesgpdd\n" \
"# application/vnd.dvb.ipdcroaming\n" \
"# application/vnd.dvb.iptv.alfec-base\n" \
"# application/vnd.dvb.iptv.alfec-enhancement\n" \
"# application/vnd.dvb.notif-aggregate-root+xml\n" \
"# application/vnd.dvb.notif-container+xml\n" \
"# application/vnd.dvb.notif-generic+xml\n" \
"# application/vnd.dvb.notif-ia-msglist+xml\n" \
"# application/vnd.dvb.notif-ia-registration-request+xml\n" \
"# application/vnd.dvb.notif-ia-registration-response+xml\n" \
"# application/vnd.dvb.notif-init+xml\n" \
"# application/vnd.dvb.pfr\n" \
"application/vnd.dvb.service			svc\n" \
"# application/vnd.dxr\n" \
"application/vnd.dynageo				geo\n" \
"# application/vnd.easykaraoke.cdgdownload\n" \
"# application/vnd.ecdis-update\n" \
"application/vnd.ecowin.chart			mag\n" \
"# application/vnd.ecowin.filerequest\n" \
"# application/vnd.ecowin.fileupdate\n" \
"# application/vnd.ecowin.series\n" \
"# application/vnd.ecowin.seriesrequest\n" \
"# application/vnd.ecowin.seriesupdate\n" \
"# application/vnd.emclient.accessrequest+xml\n" \
"application/vnd.enliven				nml\n" \
"# application/vnd.eprints.data+xml\n" \
"application/vnd.epson.esf			esf\n" \
"application/vnd.epson.msf			msf\n" \
"application/vnd.epson.quickanime		qam\n" \
"application/vnd.epson.salt			slt\n" \
"application/vnd.epson.ssf			ssf\n" \
"# application/vnd.ericsson.quickcall\n" \
"application/vnd.eszigno3+xml			es3 et3\n" \
"# application/vnd.etsi.aoc+xml\n" \
"# application/vnd.etsi.cug+xml\n" \
"# application/vnd.etsi.iptvcommand+xml\n" \
"# application/vnd.etsi.iptvdiscovery+xml\n" \
"# application/vnd.etsi.iptvprofile+xml\n" \
"# application/vnd.etsi.iptvsad-bc+xml\n" \
"# application/vnd.etsi.iptvsad-cod+xml\n" \
"# application/vnd.etsi.iptvsad-npvr+xml\n" \
"# application/vnd.etsi.iptvservice+xml\n" \
"# application/vnd.etsi.iptvsync+xml\n" \
"# application/vnd.etsi.iptvueprofile+xml\n" \
"# application/vnd.etsi.mcid+xml\n" \
"# application/vnd.etsi.overload-control-policy-dataset+xml\n" \
"# application/vnd.etsi.sci+xml\n" \
"# application/vnd.etsi.simservs+xml\n" \
"# application/vnd.etsi.tsl+xml\n" \
"# application/vnd.etsi.tsl.der\n" \
"# application/vnd.eudora.data\n" \
"application/vnd.ezpix-album			ez2\n" \
"application/vnd.ezpix-package			ez3\n" \
"# application/vnd.f-secure.mobile\n" \
"application/vnd.fdf				fdf\n" \
"application/vnd.fdsn.mseed			mseed\n" \
"application/vnd.fdsn.seed			seed dataless\n" \
"# application/vnd.ffsns\n" \
"# application/vnd.fints\n" \
"application/vnd.flographit			gph\n" \
"application/vnd.fluxtime.clip			ftc\n" \
"# application/vnd.font-fontforge-sfd\n" \
"application/vnd.framemaker			fm frame maker book\n" \
"application/vnd.frogans.fnc			fnc\n" \
"application/vnd.frogans.ltf			ltf\n" \
"application/vnd.fsc.weblaunch			fsc\n" \
"application/vnd.fujitsu.oasys			oas\n" \
"application/vnd.fujitsu.oasys2			oa2\n" \
"application/vnd.fujitsu.oasys3			oa3\n" \
"application/vnd.fujitsu.oasysgp			fg5\n" \
"application/vnd.fujitsu.oasysprs		bh2\n" \
"# application/vnd.fujixerox.art-ex\n" \
"# application/vnd.fujixerox.art4\n" \
"# application/vnd.fujixerox.hbpl\n" \
"application/vnd.fujixerox.ddd			ddd\n" \
"application/vnd.fujixerox.docuworks		xdw\n" \
"application/vnd.fujixerox.docuworks.binder	xbd\n" \
"# application/vnd.fut-misnet\n" \
"application/vnd.fuzzysheet			fzs\n" \
"application/vnd.genomatix.tuxedo		txd\n" \
"# application/vnd.geocube+xml\n" \
"application/vnd.geogebra.file			ggb\n" \
"application/vnd.geogebra.tool			ggt\n" \
"application/vnd.geometry-explorer		gex gre\n" \
"application/vnd.geonext				gxt\n" \
"application/vnd.geoplan				g2w\n" \
"application/vnd.geospace			g3w\n" \
"# application/vnd.globalplatform.card-content-mgt\n" \
"# application/vnd.globalplatform.card-content-mgt-response\n" \
"application/vnd.gmx				gmx\n" \
"application/vnd.google-earth.kml+xml		kml\n" \
"application/vnd.google-earth.kmz		kmz\n" \
"application/vnd.grafeq				gqf gqs\n" \
"# application/vnd.gridmp\n" \
"application/vnd.groove-account			gac\n" \
"application/vnd.groove-help			ghf\n" \
"application/vnd.groove-identity-message		gim\n" \
"application/vnd.groove-injector			grv\n" \
"application/vnd.groove-tool-message		gtm\n" \
"application/vnd.groove-tool-template		tpl\n" \
"application/vnd.groove-vcard			vcg\n" \
"# application/vnd.hal+json\n" \
"application/vnd.hal+xml				hal\n" \
"application/vnd.handheld-entertainment+xml	zmm\n" \
"application/vnd.hbci				hbci\n" \
"# application/vnd.hcl-bireports\n" \
"application/vnd.hhe.lesson-player		les\n" \
"application/vnd.hp-hpgl				hpgl\n" \
"application/vnd.hp-hpid				hpid\n" \
"application/vnd.hp-hps				hps\n" \
"application/vnd.hp-jlyt				jlt\n" \
"application/vnd.hp-pcl				pcl\n" \
"application/vnd.hp-pclxl			pclxl\n" \
"# application/vnd.httphone\n" \
"application/vnd.hydrostatix.sof-data		sfd-hdstx\n" \
"# application/vnd.hzn-3d-crossword\n" \
"# application/vnd.ibm.afplinedata\n" \
"# application/vnd.ibm.electronic-media\n" \
"application/vnd.ibm.minipay			mpy\n" \
"application/vnd.ibm.modcap			afp listafp list3820\n" \
"application/vnd.ibm.rights-management		irm\n" \
"application/vnd.ibm.secure-container		sc\n" \
"application/vnd.iccprofile			icc icm\n" \
"application/vnd.igloader			igl\n" \
"application/vnd.immervision-ivp			ivp\n" \
"application/vnd.immervision-ivu			ivu\n" \
"# application/vnd.informedcontrol.rms+xml\n" \
"# application/vnd.informix-visionary\n" \
"# application/vnd.infotech.project\n" \
"# application/vnd.infotech.project+xml\n" \
"# application/vnd.innopath.wamp.notification\n" \
"application/vnd.insors.igm			igm\n" \
"application/vnd.intercon.formnet		xpw xpx\n" \
"application/vnd.intergeo			i2g\n" \
"# application/vnd.intertrust.digibox\n" \
"# application/vnd.intertrust.nncp\n" \
"application/vnd.intu.qbo			qbo\n" \
"application/vnd.intu.qfx			qfx\n" \
"# application/vnd.iptc.g2.conceptitem+xml\n" \
"# application/vnd.iptc.g2.knowledgeitem+xml\n" \
"# application/vnd.iptc.g2.newsitem+xml\n" \
"# application/vnd.iptc.g2.newsmessage+xml\n" \
"# application/vnd.iptc.g2.packageitem+xml\n" \
"# application/vnd.iptc.g2.planningitem+xml\n" \
"application/vnd.ipunplugged.rcprofile		rcprofile\n" \
"application/vnd.irepository.package+xml		irp\n" \
"application/vnd.is-xpr				xpr\n" \
"application/vnd.isac.fcs			fcs\n" \
"application/vnd.jam				jam\n" \
"# application/vnd.japannet-directory-service\n" \
"# application/vnd.japannet-jpnstore-wakeup\n" \
"# application/vnd.japannet-payment-wakeup\n" \
"# application/vnd.japannet-registration\n" \
"# application/vnd.japannet-registration-wakeup\n" \
"# application/vnd.japannet-setstore-wakeup\n" \
"# application/vnd.japannet-verification\n" \
"# application/vnd.japannet-verification-wakeup\n" \
"application/vnd.jcp.javame.midlet-rms		rms\n" \
"application/vnd.jisp				jisp\n" \
"application/vnd.joost.joda-archive		joda\n" \
"application/vnd.kahootz				ktz ktr\n" \
"application/vnd.kde.karbon			karbon\n" \
"application/vnd.kde.kchart			chrt\n" \
"application/vnd.kde.kformula			kfo\n" \
"application/vnd.kde.kivio			flw\n" \
"application/vnd.kde.kontour			kon\n" \
"application/vnd.kde.kpresenter			kpr kpt\n" \
"application/vnd.kde.kspread			ksp\n" \
"application/vnd.kde.kword			kwd kwt\n" \
"application/vnd.kenameaapp			htke\n" \
"application/vnd.kidspiration			kia\n" \
"application/vnd.kinar				kne knp\n" \
"application/vnd.koan				skp skd skt skm\n" \
"application/vnd.kodak-descriptor		sse\n" \
"application/vnd.las.las+xml			lasxml\n" \
"# application/vnd.liberty-request+xml\n" \
"application/vnd.llamagraphics.life-balance.desktop	lbd\n" \
"application/vnd.llamagraphics.life-balance.exchange+xml	lbe\n" \
"application/vnd.lotus-1-2-3			123\n" \
"application/vnd.lotus-approach			apr\n" \
"application/vnd.lotus-freelance			pre\n" \
"application/vnd.lotus-notes			nsf\n" \
"application/vnd.lotus-organizer			org\n" \
"application/vnd.lotus-screencam			scm\n" \
"application/vnd.lotus-wordpro			lwp\n" \
"application/vnd.macports.portpkg		portpkg\n" \
"# application/vnd.marlin.drm.actiontoken+xml\n" \
"# application/vnd.marlin.drm.conftoken+xml\n" \
"# application/vnd.marlin.drm.license+xml\n" \
"# application/vnd.marlin.drm.mdcf\n" \
"application/vnd.mcd				mcd\n" \
"application/vnd.medcalcdata			mc1\n" \
"application/vnd.mediastation.cdkey		cdkey\n" \
"# application/vnd.meridian-slingshot\n" \
"application/vnd.mfer				mwf\n" \
"application/vnd.mfmp				mfm\n" \
"application/vnd.micrografx.flo			flo\n" \
"application/vnd.micrografx.igx			igx\n" \
"application/vnd.mif				mif\n" \
"# application/vnd.minisoft-hp3000-save\n" \
"# application/vnd.mitsubishi.misty-guard.trustweb\n" \
"application/vnd.mobius.daf			daf\n" \
"application/vnd.mobius.dis			dis\n" \
"application/vnd.mobius.mbk			mbk\n" \
"application/vnd.mobius.mqy			mqy\n" \
"application/vnd.mobius.msl			msl\n" \
"application/vnd.mobius.plc			plc\n" \
"application/vnd.mobius.txf			txf\n" \
"application/vnd.mophun.application		mpn\n" \
"application/vnd.mophun.certificate		mpc\n" \
"# application/vnd.motorola.flexsuite\n" \
"# application/vnd.motorola.flexsuite.adsi\n" \
"# application/vnd.motorola.flexsuite.fis\n" \
"# application/vnd.motorola.flexsuite.gotap\n" \
"# application/vnd.motorola.flexsuite.kmr\n" \
"# application/vnd.motorola.flexsuite.ttc\n" \
"# application/vnd.motorola.flexsuite.wem\n" \
"# application/vnd.motorola.iprm\n" \
"application/vnd.mozilla.xul+xml			xul\n" \
"application/vnd.ms-artgalry			cil\n" \
"# application/vnd.ms-asf\n" \
"application/vnd.ms-cab-compressed		cab\n" \
"# application/vnd.ms-color.iccprofile\n" \
"application/vnd.ms-excel			xls xlm xla xlc xlt xlw\n" \
"application/vnd.ms-excel.addin.macroenabled.12		xlam\n" \
"application/vnd.ms-excel.sheet.binary.macroenabled.12	xlsb\n" \
"application/vnd.ms-excel.sheet.macroenabled.12		xlsm\n" \
"application/vnd.ms-excel.template.macroenabled.12	xltm\n" \
"application/vnd.ms-fontobject			eot\n" \
"application/vnd.ms-htmlhelp			chm\n" \
"application/vnd.ms-ims				ims\n" \
"application/vnd.ms-lrm				lrm\n" \
"# application/vnd.ms-office.activex+xml\n" \
"application/vnd.ms-officetheme			thmx\n" \
"# application/vnd.ms-opentype\n" \
"# application/vnd.ms-package.obfuscated-opentype\n" \
"application/vnd.ms-pki.seccat			cat\n" \
"application/vnd.ms-pki.stl			stl\n" \
"# application/vnd.ms-playready.initiator+xml\n" \
"application/vnd.ms-powerpoint			ppt pps pot\n" \
"application/vnd.ms-powerpoint.addin.macroenabled.12		ppam\n" \
"application/vnd.ms-powerpoint.presentation.macroenabled.12	pptm\n" \
"application/vnd.ms-powerpoint.slide.macroenabled.12		sldm\n" \
"application/vnd.ms-powerpoint.slideshow.macroenabled.12		ppsm\n" \
"application/vnd.ms-powerpoint.template.macroenabled.12		potm\n" \
"# application/vnd.ms-printing.printticket+xml\n" \
"application/vnd.ms-project			mpp mpt\n" \
"# application/vnd.ms-tnef\n" \
"# application/vnd.ms-wmdrm.lic-chlg-req\n" \
"# application/vnd.ms-wmdrm.lic-resp\n" \
"# application/vnd.ms-wmdrm.meter-chlg-req\n" \
"# application/vnd.ms-wmdrm.meter-resp\n" \
"application/vnd.ms-word.document.macroenabled.12	docm\n" \
"application/vnd.ms-word.template.macroenabled.12	dotm\n" \
"application/vnd.ms-works			wps wks wcm wdb\n" \
"application/vnd.ms-wpl				wpl\n" \
"application/vnd.ms-xpsdocument			xps\n" \
"application/vnd.mseq				mseq\n" \
"# application/vnd.msign\n" \
"# application/vnd.multiad.creator\n" \
"# application/vnd.multiad.creator.cif\n" \
"# application/vnd.music-niff\n" \
"application/vnd.musician			mus\n" \
"application/vnd.muvee.style			msty\n" \
"application/vnd.mynfc				taglet\n" \
"# application/vnd.ncd.control\n" \
"# application/vnd.ncd.reference\n" \
"# application/vnd.nervana\n" \
"# application/vnd.netfpx\n" \
"application/vnd.neurolanguage.nlu		nlu\n" \
"application/vnd.nitf				ntf nitf\n" \
"application/vnd.noblenet-directory		nnd\n" \
"application/vnd.noblenet-sealer			nns\n" \
"application/vnd.noblenet-web			nnw\n" \
"# application/vnd.nokia.catalogs\n" \
"# application/vnd.nokia.conml+wbxml\n" \
"# application/vnd.nokia.conml+xml\n" \
"# application/vnd.nokia.isds-radio-presets\n" \
"# application/vnd.nokia.iptv.config+xml\n" \
"# application/vnd.nokia.landmark+wbxml\n" \
"# application/vnd.nokia.landmark+xml\n" \
"# application/vnd.nokia.landmarkcollection+xml\n" \
"# application/vnd.nokia.n-gage.ac+xml\n" \
"application/vnd.nokia.n-gage.data		ngdat\n" \
"application/vnd.nokia.n-gage.symbian.install	n-gage\n" \
"# application/vnd.nokia.ncd\n" \
"# application/vnd.nokia.pcd+wbxml\n" \
"# application/vnd.nokia.pcd+xml\n" \
"application/vnd.nokia.radio-preset		rpst\n" \
"application/vnd.nokia.radio-presets		rpss\n" \
"application/vnd.novadigm.edm			edm\n" \
"application/vnd.novadigm.edx			edx\n" \
"application/vnd.novadigm.ext			ext\n" \
"# application/vnd.ntt-local.file-transfer\n" \
"# application/vnd.ntt-local.sip-ta_remote\n" \
"# application/vnd.ntt-local.sip-ta_tcp_stream\n" \
"application/vnd.oasis.opendocument.chart		odc\n" \
"application/vnd.oasis.opendocument.chart-template	otc\n" \
"application/vnd.oasis.opendocument.database		odb\n" \
"application/vnd.oasis.opendocument.formula		odf\n" \
"application/vnd.oasis.opendocument.formula-template	odft\n" \
"application/vnd.oasis.opendocument.graphics		odg\n" \
"application/vnd.oasis.opendocument.graphics-template	otg\n" \
"application/vnd.oasis.opendocument.image		odi\n" \
"application/vnd.oasis.opendocument.image-template	oti\n" \
"application/vnd.oasis.opendocument.presentation		odp\n" \
"application/vnd.oasis.opendocument.presentation-template	otp\n" \
"application/vnd.oasis.opendocument.spreadsheet		ods\n" \
"application/vnd.oasis.opendocument.spreadsheet-template	ots\n" \
"application/vnd.oasis.opendocument.text			odt\n" \
"application/vnd.oasis.opendocument.text-master		odm\n" \
"application/vnd.oasis.opendocument.text-template	ott\n" \
"application/vnd.oasis.opendocument.text-web		oth\n" \
"# application/vnd.obn\n" \
"# application/vnd.oftn.l10n+json\n" \
"# application/vnd.oipf.contentaccessdownload+xml\n" \
"# application/vnd.oipf.contentaccessstreaming+xml\n" \
"# application/vnd.oipf.cspg-hexbinary\n" \
"# application/vnd.oipf.dae.svg+xml\n" \
"# application/vnd.oipf.dae.xhtml+xml\n" \
"# application/vnd.oipf.mippvcontrolmessage+xml\n" \
"# application/vnd.oipf.pae.gem\n" \
"# application/vnd.oipf.spdiscovery+xml\n" \
"# application/vnd.oipf.spdlist+xml\n" \
"# application/vnd.oipf.ueprofile+xml\n" \
"# application/vnd.oipf.userprofile+xml\n" \
"application/vnd.olpc-sugar			xo\n" \
"# application/vnd.oma-scws-config\n" \
"# application/vnd.oma-scws-http-request\n" \
"# application/vnd.oma-scws-http-response\n" \
"# application/vnd.oma.bcast.associated-procedure-parameter+xml\n" \
"# application/vnd.oma.bcast.drm-trigger+xml\n" \
"# application/vnd.oma.bcast.imd+xml\n" \
"# application/vnd.oma.bcast.ltkm\n" \
"# application/vnd.oma.bcast.notification+xml\n" \
"# application/vnd.oma.bcast.provisioningtrigger\n" \
"# application/vnd.oma.bcast.sgboot\n" \
"# application/vnd.oma.bcast.sgdd+xml\n" \
"# application/vnd.oma.bcast.sgdu\n" \
"# application/vnd.oma.bcast.simple-symbol-container\n" \
"# application/vnd.oma.bcast.smartcard-trigger+xml\n" \
"# application/vnd.oma.bcast.sprov+xml\n" \
"# application/vnd.oma.bcast.stkm\n" \
"# application/vnd.oma.cab-address-book+xml\n" \
"# application/vnd.oma.cab-feature-handler+xml\n" \
"# application/vnd.oma.cab-pcc+xml\n" \
"# application/vnd.oma.cab-user-prefs+xml\n" \
"# application/vnd.oma.dcd\n" \
"# application/vnd.oma.dcdc\n" \
"application/vnd.oma.dd2+xml			dd2\n" \
"# application/vnd.oma.drm.risd+xml\n" \
"# application/vnd.oma.group-usage-list+xml\n" \
"# application/vnd.oma.pal+xml\n" \
"# application/vnd.oma.poc.detailed-progress-report+xml\n" \
"# application/vnd.oma.poc.final-report+xml\n" \
"# application/vnd.oma.poc.groups+xml\n" \
"# application/vnd.oma.poc.invocation-descriptor+xml\n" \
"# application/vnd.oma.poc.optimized-progress-report+xml\n" \
"# application/vnd.oma.push\n" \
"# application/vnd.oma.scidm.messages+xml\n" \
"# application/vnd.oma.xcap-directory+xml\n" \
"# application/vnd.omads-email+xml\n" \
"# application/vnd.omads-file+xml\n" \
"# application/vnd.omads-folder+xml\n" \
"# application/vnd.omaloc-supl-init\n" \
"application/vnd.openofficeorg.extension		oxt\n" \
"# application/vnd.openxmlformats-officedocument.custom-properties+xml\n" \
"# application/vnd.openxmlformats-officedocument.customxmlproperties+xml\n" \
"# application/vnd.openxmlformats-officedocument.drawing+xml\n" \
"# application/vnd.openxmlformats-officedocument.drawingml.chart+xml\n" \
"# application/vnd.openxmlformats-officedocument.drawingml.chartshapes+xml\n" \
"# application/vnd.openxmlformats-officedocument.drawingml.diagramcolors+xml\n" \
"# application/vnd.openxmlformats-officedocument.drawingml.diagramdata+xml\n" \
"# application/vnd.openxmlformats-officedocument.drawingml.diagramlayout+xml\n" \
"# application/vnd.openxmlformats-officedocument.drawingml.diagramstyle+xml\n" \
"# application/vnd.openxmlformats-officedocument.extended-properties+xml\n" \
"# application/vnd.openxmlformats-officedocument.presentationml.commentauthors+xml\n" \
"# application/vnd.openxmlformats-officedocument.presentationml.comments+xml\n" \
"# application/vnd.openxmlformats-officedocument.presentationml.handoutmaster+xml\n" \
"# application/vnd.openxmlformats-officedocument.presentationml.notesmaster+xml\n" \
"# application/vnd.openxmlformats-officedocument.presentationml.notesslide+xml\n" \
"application/vnd.openxmlformats-officedocument.presentationml.presentation	pptx\n" \
"# application/vnd.openxmlformats-officedocument.presentationml.presentation.main+xml\n" \
"# application/vnd.openxmlformats-officedocument.presentationml.presprops+xml\n" \
"application/vnd.openxmlformats-officedocument.presentationml.slide	sldx\n" \
"# application/vnd.openxmlformats-officedocument.presentationml.slide+xml\n" \
"# application/vnd.openxmlformats-officedocument.presentationml.slidelayout+xml\n" \
"# application/vnd.openxmlformats-officedocument.presentationml.slidemaster+xml\n" \
"application/vnd.openxmlformats-officedocument.presentationml.slideshow	ppsx\n" \
"# application/vnd.openxmlformats-officedocument.presentationml.slideshow.main+xml\n" \
"# application/vnd.openxmlformats-officedocument.presentationml.slideupdateinfo+xml\n" \
"# application/vnd.openxmlformats-officedocument.presentationml.tablestyles+xml\n" \
"# application/vnd.openxmlformats-officedocument.presentationml.tags+xml\n" \
"application/vnd.openxmlformats-officedocument.presentationml.template	potx\n" \
"# application/vnd.openxmlformats-officedocument.presentationml.template.main+xml\n" \
"# application/vnd.openxmlformats-officedocument.presentationml.viewprops+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.calcchain+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.chartsheet+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.comments+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.connections+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.dialogsheet+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.externallink+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.pivotcachedefinition+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.pivotcacherecords+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.pivottable+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.querytable+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.revisionheaders+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.revisionlog+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.sharedstrings+xml\n" \
"application/vnd.openxmlformats-officedocument.spreadsheetml.sheet	xlsx\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.sheet.main+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.sheetmetadata+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.styles+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.table+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.tablesinglecells+xml\n" \
"application/vnd.openxmlformats-officedocument.spreadsheetml.template	xltx\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.template.main+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.usernames+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.volatiledependencies+xml\n" \
"# application/vnd.openxmlformats-officedocument.spreadsheetml.worksheet+xml\n" \
"# application/vnd.openxmlformats-officedocument.theme+xml\n" \
"# application/vnd.openxmlformats-officedocument.themeoverride+xml\n" \
"# application/vnd.openxmlformats-officedocument.vmldrawing\n" \
"# application/vnd.openxmlformats-officedocument.wordprocessingml.comments+xml\n" \
"application/vnd.openxmlformats-officedocument.wordprocessingml.document	docx\n" \
"# application/vnd.openxmlformats-officedocument.wordprocessingml.document.glossary+xml\n" \
"# application/vnd.openxmlformats-officedocument.wordprocessingml.document.main+xml\n" \
"# application/vnd.openxmlformats-officedocument.wordprocessingml.endnotes+xml\n" \
"# application/vnd.openxmlformats-officedocument.wordprocessingml.fonttable+xml\n" \
"# application/vnd.openxmlformats-officedocument.wordprocessingml.footer+xml\n" \
"# application/vnd.openxmlformats-officedocument.wordprocessingml.footnotes+xml\n" \
"# application/vnd.openxmlformats-officedocument.wordprocessingml.numbering+xml\n" \
"# application/vnd.openxmlformats-officedocument.wordprocessingml.settings+xml\n" \
"# application/vnd.openxmlformats-officedocument.wordprocessingml.styles+xml\n" \
"application/vnd.openxmlformats-officedocument.wordprocessingml.template	dotx\n" \
"# application/vnd.openxmlformats-officedocument.wordprocessingml.template.main+xml\n" \
"# application/vnd.openxmlformats-officedocument.wordprocessingml.websettings+xml\n" \
"# application/vnd.openxmlformats-package.core-properties+xml\n" \
"# application/vnd.openxmlformats-package.digital-signature-xmlsignature+xml\n" \
"# application/vnd.openxmlformats-package.relationships+xml\n" \
"# application/vnd.quobject-quoxdocument\n" \
"# application/vnd.osa.netdeploy\n" \
"application/vnd.osgeo.mapguide.package		mgp\n" \
"# application/vnd.osgi.bundle\n" \
"application/vnd.osgi.dp				dp\n" \
"application/vnd.osgi.subsystem			esa\n" \
"# application/vnd.otps.ct-kip+xml\n" \
"application/vnd.palm				pdb pqa oprc\n" \
"# application/vnd.paos.xml\n" \
"application/vnd.pawaafile			paw\n" \
"application/vnd.pg.format			str\n" \
"application/vnd.pg.osasli			ei6\n" \
"# application/vnd.piaccess.application-licence\n" \
"application/vnd.picsel				efif\n" \
"application/vnd.pmi.widget			wg\n" \
"# application/vnd.poc.group-advertisement+xml\n" \
"application/vnd.pocketlearn			plf\n" \
"application/vnd.powerbuilder6			pbd\n" \
"# application/vnd.powerbuilder6-s\n" \
"# application/vnd.powerbuilder7\n" \
"# application/vnd.powerbuilder7-s\n" \
"# application/vnd.powerbuilder75\n" \
"# application/vnd.powerbuilder75-s\n" \
"# application/vnd.preminet\n" \
"application/vnd.previewsystems.box		box\n" \
"application/vnd.proteus.magazine		mgz\n" \
"application/vnd.publishare-delta-tree		qps\n" \
"application/vnd.pvi.ptid1			ptid\n" \
"# application/vnd.pwg-multiplexed\n" \
"# application/vnd.pwg-xhtml-print+xml\n" \
"# application/vnd.qualcomm.brew-app-res\n" \
"application/vnd.quark.quarkxpress		qxd qxt qwd qwt qxl qxb\n" \
"# application/vnd.radisys.moml+xml\n" \
"# application/vnd.radisys.msml+xml\n" \
"# application/vnd.radisys.msml-audit+xml\n" \
"# application/vnd.radisys.msml-audit-conf+xml\n" \
"# application/vnd.radisys.msml-audit-conn+xml\n" \
"# application/vnd.radisys.msml-audit-dialog+xml\n" \
"# application/vnd.radisys.msml-audit-stream+xml\n" \
"# application/vnd.radisys.msml-conf+xml\n" \
"# application/vnd.radisys.msml-dialog+xml\n" \
"# application/vnd.radisys.msml-dialog-base+xml\n" \
"# application/vnd.radisys.msml-dialog-fax-detect+xml\n" \
"# application/vnd.radisys.msml-dialog-fax-sendrecv+xml\n" \
"# application/vnd.radisys.msml-dialog-group+xml\n" \
"# application/vnd.radisys.msml-dialog-speech+xml\n" \
"# application/vnd.radisys.msml-dialog-transform+xml\n" \
"# application/vnd.rainstor.data\n" \
"# application/vnd.rapid\n" \
"application/vnd.realvnc.bed			bed\n" \
"application/vnd.recordare.musicxml		mxl\n" \
"application/vnd.recordare.musicxml+xml		musicxml\n" \
"# application/vnd.renlearn.rlprint\n" \
"application/vnd.rig.cryptonote			cryptonote\n" \
"application/vnd.rim.cod				cod\n" \
"application/vnd.rn-realmedia			rm\n" \
"application/vnd.rn-realmedia-vbr		rmvb\n" \
"application/vnd.route66.link66+xml		link66\n" \
"# application/vnd.rs-274x\n" \
"# application/vnd.ruckus.download\n" \
"# application/vnd.s3sms\n" \
"application/vnd.sailingtracker.track		st\n" \
"# application/vnd.sbm.cid\n" \
"# application/vnd.sbm.mid2\n" \
"# application/vnd.scribus\n" \
"# application/vnd.sealed.3df\n" \
"# application/vnd.sealed.csf\n" \
"# application/vnd.sealed.doc\n" \
"# application/vnd.sealed.eml\n" \
"# application/vnd.sealed.mht\n" \
"# application/vnd.sealed.net\n" \
"# application/vnd.sealed.ppt\n" \
"# application/vnd.sealed.tiff\n" \
"# application/vnd.sealed.xls\n" \
"# application/vnd.sealedmedia.softseal.html\n" \
"# application/vnd.sealedmedia.softseal.pdf\n" \
"application/vnd.seemail				see\n" \
"application/vnd.sema				sema\n" \
"application/vnd.semd				semd\n" \
"application/vnd.semf				semf\n" \
"application/vnd.shana.informed.formdata		ifm\n" \
"application/vnd.shana.informed.formtemplate	itp\n" \
"application/vnd.shana.informed.interchange	iif\n" \
"application/vnd.shana.informed.package		ipk\n" \
"application/vnd.simtech-mindmapper		twd twds\n" \
"application/vnd.smaf				mmf\n" \
"# application/vnd.smart.notebook\n" \
"application/vnd.smart.teacher			teacher\n" \
"# application/vnd.software602.filler.form+xml\n" \
"# application/vnd.software602.filler.form-xml-zip\n" \
"application/vnd.solent.sdkm+xml			sdkm sdkd\n" \
"application/vnd.spotfire.dxp			dxp\n" \
"application/vnd.spotfire.sfs			sfs\n" \
"# application/vnd.sss-cod\n" \
"# application/vnd.sss-dtf\n" \
"# application/vnd.sss-ntf\n" \
"application/vnd.stardivision.calc		sdc\n" \
"application/vnd.stardivision.draw		sda\n" \
"application/vnd.stardivision.impress		sdd\n" \
"application/vnd.stardivision.math		smf\n" \
"application/vnd.stardivision.writer		sdw vor\n" \
"application/vnd.stardivision.writer-global	sgl\n" \
"application/vnd.stepmania.package		smzip\n" \
"application/vnd.stepmania.stepchart		sm\n" \
"# application/vnd.street-stream\n" \
"application/vnd.sun.xml.calc			sxc\n" \
"application/vnd.sun.xml.calc.template		stc\n" \
"application/vnd.sun.xml.draw			sxd\n" \
"application/vnd.sun.xml.draw.template		std\n" \
"application/vnd.sun.xml.impress			sxi\n" \
"application/vnd.sun.xml.impress.template	sti\n" \
"application/vnd.sun.xml.math			sxm\n" \
"application/vnd.sun.xml.writer			sxw\n" \
"application/vnd.sun.xml.writer.global		sxg\n" \
"application/vnd.sun.xml.writer.template		stw\n" \
"# application/vnd.sun.wadl+xml\n" \
"application/vnd.sus-calendar			sus susp\n" \
"application/vnd.svd				svd\n" \
"# application/vnd.swiftview-ics\n" \
"application/vnd.symbian.install			sis sisx\n" \
"application/vnd.syncml+xml			xsm\n" \
"application/vnd.syncml.dm+wbxml			bdm\n" \
"application/vnd.syncml.dm+xml			xdm\n" \
"# application/vnd.syncml.dm.notification\n" \
"# application/vnd.syncml.ds.notification\n" \
"application/vnd.tao.intent-module-archive	tao\n" \
"application/vnd.tcpdump.pcap			pcap cap dmp\n" \
"application/vnd.tmobile-livetv			tmo\n" \
"application/vnd.trid.tpt			tpt\n" \
"application/vnd.triscape.mxs			mxs\n" \
"application/vnd.trueapp				tra\n" \
"# application/vnd.truedoc\n" \
"# application/vnd.ubisoft.webplayer\n" \
"application/vnd.ufdl				ufd ufdl\n" \
"application/vnd.uiq.theme			utz\n" \
"application/vnd.umajin				umj\n" \
"application/vnd.unity				unityweb\n" \
"application/vnd.uoml+xml			uoml\n" \
"# application/vnd.uplanet.alert\n" \
"# application/vnd.uplanet.alert-wbxml\n" \
"# application/vnd.uplanet.bearer-choice\n" \
"# application/vnd.uplanet.bearer-choice-wbxml\n" \
"# application/vnd.uplanet.cacheop\n" \
"# application/vnd.uplanet.cacheop-wbxml\n" \
"# application/vnd.uplanet.channel\n" \
"# application/vnd.uplanet.channel-wbxml\n" \
"# application/vnd.uplanet.list\n" \
"# application/vnd.uplanet.list-wbxml\n" \
"# application/vnd.uplanet.listcmd\n" \
"# application/vnd.uplanet.listcmd-wbxml\n" \
"# application/vnd.uplanet.signal\n" \
"application/vnd.vcx				vcx\n" \
"# application/vnd.vd-study\n" \
"# application/vnd.vectorworks\n" \
"# application/vnd.verimatrix.vcas\n" \
"# application/vnd.vidsoft.vidconference\n" \
"application/vnd.visio				vsd vst vss vsw\n" \
"application/vnd.visionary			vis\n" \
"# application/vnd.vividence.scriptfile\n" \
"application/vnd.vsf				vsf\n" \
"# application/vnd.wap.sic\n" \
"# application/vnd.wap.slc\n" \
"application/vnd.wap.wbxml			wbxml\n" \
"application/vnd.wap.wmlc			wmlc\n" \
"application/vnd.wap.wmlscriptc			wmlsc\n" \
"application/vnd.webturbo			wtb\n" \
"# application/vnd.wfa.wsc\n" \
"# application/vnd.wmc\n" \
"# application/vnd.wmf.bootstrap\n" \
"# application/vnd.wolfram.mathematica\n" \
"# application/vnd.wolfram.mathematica.package\n" \
"application/vnd.wolfram.player			nbp\n" \
"application/vnd.wordperfect			wpd\n" \
"application/vnd.wqd				wqd\n" \
"# application/vnd.wrq-hp3000-labelled\n" \
"application/vnd.wt.stf				stf\n" \
"# application/vnd.wv.csp+wbxml\n" \
"# application/vnd.wv.csp+xml\n" \
"# application/vnd.wv.ssp+xml\n" \
"application/vnd.xara				xar\n" \
"application/vnd.xfdl				xfdl\n" \
"# application/vnd.xfdl.webform\n" \
"# application/vnd.xmi+xml\n" \
"# application/vnd.xmpie.cpkg\n" \
"# application/vnd.xmpie.dpkg\n" \
"# application/vnd.xmpie.plan\n" \
"# application/vnd.xmpie.ppkg\n" \
"# application/vnd.xmpie.xlim\n" \
"application/vnd.yamaha.hv-dic			hvd\n" \
"application/vnd.yamaha.hv-script		hvs\n" \
"application/vnd.yamaha.hv-voice			hvp\n" \
"application/vnd.yamaha.openscoreformat			osf\n" \
"application/vnd.yamaha.openscoreformat.osfpvg+xml	osfpvg\n" \
"# application/vnd.yamaha.remote-setup\n" \
"application/vnd.yamaha.smaf-audio		saf\n" \
"application/vnd.yamaha.smaf-phrase		spf\n" \
"# application/vnd.yamaha.through-ngn\n" \
"# application/vnd.yamaha.tunnel-udpencap\n" \
"application/vnd.yellowriver-custom-menu		cmp\n" \
"application/vnd.zul				zir zirz\n" \
"application/vnd.zzazz.deck+xml			zaz\n" \
"application/voicexml+xml			vxml\n" \
"# application/vq-rtcpxr\n" \
"# application/watcherinfo+xml\n" \
"# application/whoispp-query\n" \
"# application/whoispp-response\n" \
"application/widget				wgt\n" \
"application/winhlp				hlp\n" \
"# application/wita\n" \
"# application/wordperfect5.1\n" \
"application/wsdl+xml				wsdl\n" \
"application/wspolicy+xml			wspolicy\n" \
"application/x-7z-compressed			7z\n" \
"application/x-abiword				abw\n" \
"application/x-ace-compressed			ace\n" \
"# application/x-amf\n" \
"application/x-apple-diskimage			dmg\n" \
"application/x-authorware-bin			aab x32 u32 vox\n" \
"application/x-authorware-map			aam\n" \
"application/x-authorware-seg			aas\n" \
"application/x-bcpio				bcpio\n" \
"application/x-bittorrent			torrent\n" \
"application/x-blorb				blb blorb\n" \
"application/x-bzip				bz\n" \
"application/x-bzip2				bz2 boz\n" \
"application/x-cbr				cbr cba cbt cbz cb7\n" \
"application/x-cdlink				vcd\n" \
"application/x-cfs-compressed			cfs\n" \
"application/x-chat				chat\n" \
"application/x-chess-pgn				pgn\n" \
"application/x-conference			nsc\n" \
"# application/x-compress\n" \
"application/x-cpio				cpio\n" \
"application/x-csh				csh\n" \
"application/x-debian-package			deb udeb\n" \
"application/x-dgc-compressed			dgc\n" \
"application/x-director			dir dcr dxr cst cct cxt w3d fgd swa\n" \
"application/x-doom				wad\n" \
"application/x-dtbncx+xml			ncx\n" \
"application/x-dtbook+xml			dtb\n" \
"application/x-dtbresource+xml			res\n" \
"application/x-dvi				dvi\n" \
"application/x-envoy				evy\n" \
"application/x-eva				eva\n" \
"application/x-font-bdf				bdf\n" \
"# application/x-font-dos\n" \
"# application/x-font-framemaker\n" \
"application/x-font-ghostscript			gsf\n" \
"# application/x-font-libgrx\n" \
"application/x-font-linux-psf			psf\n" \
"application/x-font-otf				otf\n" \
"application/x-font-pcf				pcf\n" \
"application/x-font-snf				snf\n" \
"# application/x-font-speedo\n" \
"# application/x-font-sunos-news\n" \
"application/x-font-ttf				ttf ttc\n" \
"application/x-font-type1			pfa pfb pfm afm\n" \
"application/font-woff				woff\n" \
"# application/x-font-vfont\n" \
"application/x-freearc				arc\n" \
"application/x-futuresplash			spl\n" \
"application/x-gca-compressed			gca\n" \
"application/x-glulx				ulx\n" \
"application/x-gnumeric				gnumeric\n" \
"application/x-gramps-xml			gramps\n" \
"application/x-gtar				gtar\n" \
"# application/x-gzip\n" \
"application/x-hdf				hdf\n" \
"application/x-install-instructions		install\n" \
"application/x-iso9660-image			iso\n" \
"application/x-java-jnlp-file			jnlp\n" \
"application/x-latex				latex\n" \
"application/x-lzh-compressed			lzh lha\n" \
"application/x-mie				mie\n" \
"application/x-mobipocket-ebook			prc mobi\n" \
"application/x-ms-application			application\n" \
"application/x-ms-shortcut			lnk\n" \
"application/x-ms-wmd				wmd\n" \
"application/x-ms-wmz				wmz\n" \
"application/x-ms-xbap				xbap\n" \
"application/x-msaccess				mdb\n" \
"application/x-msbinder				obd\n" \
"application/x-mscardfile			crd\n" \
"application/x-msclip				clp\n" \
"application/x-msdownload			exe dll com bat msi\n" \
"application/x-msmediaview			mvb m13 m14\n" \
"application/x-msmetafile			wmf wmz emf emz\n" \
"application/x-msmoney				mny\n" \
"application/x-mspublisher			pub\n" \
"application/x-msschedule			scd\n" \
"application/x-msterminal			trm\n" \
"application/x-mswrite				wri\n" \
"application/x-netcdf				nc cdf\n" \
"application/x-nzb				nzb\n" \
"application/x-pkcs12				p12 pfx\n" \
"application/x-pkcs7-certificates		p7b spc\n" \
"application/x-pkcs7-certreqresp			p7r\n" \
"application/x-rar-compressed			rar\n" \
"application/x-research-info-systems		ris\n" \
"application/x-sh				sh\n" \
"application/x-shar				shar\n" \
"application/x-shockwave-flash			swf\n" \
"application/x-silverlight-app			xap\n" \
"application/x-sql				sql\n" \
"application/x-stuffit				sit\n" \
"application/x-stuffitx				sitx\n" \
"application/x-subrip				srt\n" \
"application/x-sv4cpio				sv4cpio\n" \
"application/x-sv4crc				sv4crc\n" \
"application/x-t3vm-image			t3\n" \
"application/x-tads				gam\n" \
"application/x-tar				tar\n" \
"application/x-tcl				tcl\n" \
"application/x-tex				tex\n" \
"application/x-tex-tfm				tfm\n" \
"application/x-texinfo				texinfo texi\n" \
"application/x-tgif				obj\n" \
"application/x-ustar				ustar\n" \
"application/x-wais-source			src\n" \
"application/x-x509-ca-cert			der crt\n" \
"application/x-xfig				fig\n" \
"application/x-xliff+xml				xlf\n" \
"application/x-xpinstall				xpi\n" \
"application/x-xz				xz\n" \
"application/x-zmachine				z1 z2 z3 z4 z5 z6 z7 z8\n" \
"# application/x400-bp\n" \
"application/xaml+xml				xaml\n" \
"# application/xcap-att+xml\n" \
"# application/xcap-caps+xml\n" \
"application/xcap-diff+xml			xdf\n" \
"# application/xcap-el+xml\n" \
"# application/xcap-error+xml\n" \
"# application/xcap-ns+xml\n" \
"# application/xcon-conference-info-diff+xml\n" \
"# application/xcon-conference-info+xml\n" \
"application/xenc+xml				xenc\n" \
"application/xhtml+xml				xhtml xht\n" \
"# application/xhtml-voice+xml\n" \
"application/xml					xml xsl\n" \
"application/xml-dtd				dtd\n" \
"# application/xml-external-parsed-entity\n" \
"# application/xmpp+xml\n" \
"application/xop+xml				xop\n" \
"application/xproc+xml				xpl\n" \
"application/xslt+xml				xslt\n" \
"application/xspf+xml				xspf\n" \
"application/xv+xml				mxml xhvml xvml xvm\n" \
"application/yang				yang\n" \
"application/yin+xml				yin\n" \
"application/zip					zip\n" \
"# audio/1d-interleaved-parityfec\n" \
"# audio/32kadpcm\n" \
"# audio/3gpp\n" \
"# audio/3gpp2\n" \
"# audio/ac3\n" \
"audio/adpcm					adp\n" \
"# audio/amr\n" \
"# audio/amr-wb\n" \
"# audio/amr-wb+\n" \
"# audio/asc\n" \
"# audio/atrac-advanced-lossless\n" \
"# audio/atrac-x\n" \
"# audio/atrac3\n" \
"audio/basic					au snd\n" \
"# audio/bv16\n" \
"# audio/bv32\n" \
"# audio/clearmode\n" \
"# audio/cn\n" \
"# audio/dat12\n" \
"# audio/dls\n" \
"# audio/dsr-es201108\n" \
"# audio/dsr-es202050\n" \
"# audio/dsr-es202211\n" \
"# audio/dsr-es202212\n" \
"# audio/dv\n" \
"# audio/dvi4\n" \
"# audio/eac3\n" \
"# audio/evrc\n" \
"# audio/evrc-qcp\n" \
"# audio/evrc0\n" \
"# audio/evrc1\n" \
"# audio/evrcb\n" \
"# audio/evrcb0\n" \
"# audio/evrcb1\n" \
"# audio/evrcwb\n" \
"# audio/evrcwb0\n" \
"# audio/evrcwb1\n" \
"# audio/example\n" \
"# audio/fwdred\n" \
"# audio/g719\n" \
"# audio/g722\n" \
"# audio/g7221\n" \
"# audio/g723\n" \
"# audio/g726-16\n" \
"# audio/g726-24\n" \
"# audio/g726-32\n" \
"# audio/g726-40\n" \
"# audio/g728\n" \
"# audio/g729\n" \
"# audio/g7291\n" \
"# audio/g729d\n" \
"# audio/g729e\n" \
"# audio/gsm\n" \
"# audio/gsm-efr\n" \
"# audio/gsm-hr-08\n" \
"# audio/ilbc\n" \
"# audio/ip-mr_v2.5\n" \
"# audio/isac\n" \
"# audio/l16\n" \
"# audio/l20\n" \
"# audio/l24\n" \
"# audio/l8\n" \
"# audio/lpc\n" \
"audio/midi					mid midi kar rmi\n" \
"# audio/mobile-xmf\n" \
"audio/mp4					mp4a\n" \
"# audio/mp4a-latm\n" \
"# audio/mpa\n" \
"# audio/mpa-robust\n" \
"audio/mpeg					mpga mp2 mp2a mp3 m2a m3a\n" \
"# audio/mpeg4-generic\n" \
"# audio/musepack\n" \
"audio/ogg					oga ogg spx\n" \
"# audio/opus\n" \
"# audio/parityfec\n" \
"# audio/pcma\n" \
"# audio/pcma-wb\n" \
"# audio/pcmu-wb\n" \
"# audio/pcmu\n" \
"# audio/prs.sid\n" \
"# audio/qcelp\n" \
"# audio/red\n" \
"# audio/rtp-enc-aescm128\n" \
"# audio/rtp-midi\n" \
"# audio/rtx\n" \
"audio/s3m					s3m\n" \
"audio/silk					sil\n" \
"# audio/smv\n" \
"# audio/smv0\n" \
"# audio/smv-qcp\n" \
"# audio/sp-midi\n" \
"# audio/speex\n" \
"# audio/t140c\n" \
"# audio/t38\n" \
"# audio/telephone-event\n" \
"# audio/tone\n" \
"# audio/uemclip\n" \
"# audio/ulpfec\n" \
"# audio/vdvi\n" \
"# audio/vmr-wb\n" \
"# audio/vnd.3gpp.iufp\n" \
"# audio/vnd.4sb\n" \
"# audio/vnd.audiokoz\n" \
"# audio/vnd.celp\n" \
"# audio/vnd.cisco.nse\n" \
"# audio/vnd.cmles.radio-events\n" \
"# audio/vnd.cns.anp1\n" \
"# audio/vnd.cns.inf1\n" \
"audio/vnd.dece.audio				uva uvva\n" \
"audio/vnd.digital-winds				eol\n" \
"# audio/vnd.dlna.adts\n" \
"# audio/vnd.dolby.heaac.1\n" \
"# audio/vnd.dolby.heaac.2\n" \
"# audio/vnd.dolby.mlp\n" \
"# audio/vnd.dolby.mps\n" \
"# audio/vnd.dolby.pl2\n" \
"# audio/vnd.dolby.pl2x\n" \
"# audio/vnd.dolby.pl2z\n" \
"# audio/vnd.dolby.pulse.1\n" \
"audio/vnd.dra					dra\n" \
"audio/vnd.dts					dts\n" \
"audio/vnd.dts.hd				dtshd\n" \
"# audio/vnd.dvb.file\n" \
"# audio/vnd.everad.plj\n" \
"# audio/vnd.hns.audio\n" \
"audio/vnd.lucent.voice				lvp\n" \
"audio/vnd.ms-playready.media.pya		pya\n" \
"# audio/vnd.nokia.mobile-xmf\n" \
"# audio/vnd.nortel.vbk\n" \
"audio/vnd.nuera.ecelp4800			ecelp4800\n" \
"audio/vnd.nuera.ecelp7470			ecelp7470\n" \
"audio/vnd.nuera.ecelp9600			ecelp9600\n" \
"# audio/vnd.octel.sbc\n" \
"# audio/vnd.qcelp\n" \
"# audio/vnd.rhetorex.32kadpcm\n" \
"audio/vnd.rip					rip\n" \
"# audio/vnd.sealedmedia.softseal.mpeg\n" \
"# audio/vnd.vmx.cvsd\n" \
"# audio/vorbis\n" \
"# audio/vorbis-config\n" \
"audio/webm					weba\n" \
"audio/x-aac					aac\n" \
"audio/x-aiff					aif aiff aifc\n" \
"audio/x-caf					caf\n" \
"audio/x-flac					flac\n" \
"audio/x-matroska				mka\n" \
"audio/x-mpegurl					m3u\n" \
"audio/x-ms-wax					wax\n" \
"audio/x-ms-wma					wma\n" \
"audio/x-pn-realaudio				ram ra\n" \
"audio/x-pn-realaudio-plugin			rmp\n" \
"# audio/x-tta\n" \
"audio/x-wav					wav\n" \
"audio/xm					xm\n" \
"chemical/x-cdx					cdx\n" \
"chemical/x-cif					cif\n" \
"chemical/x-cmdf					cmdf\n" \
"chemical/x-cml					cml\n" \
"chemical/x-csml					csml\n" \
"# chemical/x-pdb\n" \
"chemical/x-xyz					xyz\n" \
"image/bmp					bmp\n" \
"image/cgm					cgm\n" \
"# image/example\n" \
"# image/fits\n" \
"image/g3fax					g3\n" \
"image/gif					gif\n" \
"image/ief					ief\n" \
"# image/jp2\n" \
"image/jpeg					jpeg jpg jpe\n" \
"# image/jpm\n" \
"# image/jpx\n" \
"image/ktx					ktx\n" \
"# image/naplps\n" \
"image/png					png\n" \
"image/prs.btif					btif\n" \
"# image/prs.pti\n" \
"image/sgi					sgi\n" \
"image/svg+xml					svg svgz\n" \
"# image/t38\n" \
"image/tiff					tiff tif\n" \
"# image/tiff-fx\n" \
"image/vnd.adobe.photoshop			psd\n" \
"# image/vnd.cns.inf2\n" \
"image/vnd.dece.graphic				uvi uvvi uvg uvvg\n" \
"image/vnd.dvb.subtitle				sub\n" \
"image/vnd.djvu					djvu djv\n" \
"image/vnd.dwg					dwg\n" \
"image/vnd.dxf					dxf\n" \
"image/vnd.fastbidsheet				fbs\n" \
"image/vnd.fpx					fpx\n" \
"image/vnd.fst					fst\n" \
"image/vnd.fujixerox.edmics-mmr			mmr\n" \
"image/vnd.fujixerox.edmics-rlc			rlc\n" \
"# image/vnd.globalgraphics.pgb\n" \
"# image/vnd.microsoft.icon\n" \
"# image/vnd.mix\n" \
"image/vnd.ms-modi				mdi\n" \
"image/vnd.ms-photo				wdp\n" \
"image/vnd.net-fpx				npx\n" \
"# image/vnd.radiance\n" \
"# image/vnd.sealed.png\n" \
"# image/vnd.sealedmedia.softseal.gif\n" \
"# image/vnd.sealedmedia.softseal.jpg\n" \
"# image/vnd.svf\n" \
"image/vnd.wap.wbmp				wbmp\n" \
"image/vnd.xiff					xif\n" \
"image/webp					webp\n" \
"image/x-3ds					3ds\n" \
"image/x-cmu-raster				ras\n" \
"image/x-cmx					cmx\n" \
"image/x-freehand				fh fhc fh4 fh5 fh7\n" \
"image/x-icon					ico\n" \
"image/x-mrsid-image				sid\n" \
"image/x-pcx					pcx\n" \
"image/x-pict					pic pct\n" \
"image/x-portable-anymap				pnm\n" \
"image/x-portable-bitmap				pbm\n" \
"image/x-portable-graymap			pgm\n" \
"image/x-portable-pixmap				ppm\n" \
"image/x-rgb					rgb\n" \
"image/x-tga					tga\n" \
"image/x-xbitmap					xbm\n" \
"image/x-xpixmap					xpm\n" \
"image/x-xwindowdump				xwd\n" \
"# message/cpim\n" \
"# message/delivery-status\n" \
"# message/disposition-notification\n" \
"# message/example\n" \
"# message/external-body\n" \
"# message/feedback-report\n" \
"# message/global\n" \
"# message/global-delivery-status\n" \
"# message/global-disposition-notification\n" \
"# message/global-headers\n" \
"# message/http\n" \
"# message/imdn+xml\n" \
"# message/news\n" \
"# message/partial\n" \
"message/rfc822					eml mime\n" \
"# message/s-http\n" \
"# message/sip\n" \
"# message/sipfrag\n" \
"# message/tracking-status\n" \
"# message/vnd.si.simp\n" \
"# model/example\n" \
"model/iges					igs iges\n" \
"model/mesh					msh mesh silo\n" \
"model/vnd.collada+xml				dae\n" \
"model/vnd.dwf					dwf\n" \
"# model/vnd.flatland.3dml\n" \
"model/vnd.gdl					gdl\n" \
"# model/vnd.gs-gdl\n" \
"# model/vnd.gs.gdl\n" \
"model/vnd.gtw					gtw\n" \
"# model/vnd.moml+xml\n" \
"model/vnd.mts					mts\n" \
"# model/vnd.parasolid.transmit.binary\n" \
"# model/vnd.parasolid.transmit.text\n" \
"model/vnd.vtu					vtu\n" \
"model/vrml					wrl vrml\n" \
"model/x3d+binary				x3db x3dbz\n" \
"model/x3d+vrml					x3dv x3dvz\n" \
"model/x3d+xml					x3d x3dz\n" \
"# multipart/alternative\n" \
"# multipart/appledouble\n" \
"# multipart/byteranges\n" \
"# multipart/digest\n" \
"# multipart/encrypted\n" \
"# multipart/example\n" \
"# multipart/form-data\n" \
"# multipart/header-set\n" \
"# multipart/mixed\n" \
"# multipart/parallel\n" \
"# multipart/related\n" \
"# multipart/report\n" \
"# multipart/signed\n" \
"# multipart/voice-message\n" \
"# text/1d-interleaved-parityfec\n" \
"text/cache-manifest				appcache\n" \
"text/calendar					ics ifb\n" \
"text/css					css\n" \
"text/csv					csv\n" \
"# text/directory\n" \
"# text/dns\n" \
"# text/ecmascript\n" \
"# text/enriched\n" \
"# text/example\n" \
"# text/fwdred\n" \
"text/html					html htm\n" \
"# text/javascript\n" \
"text/n3						n3\n" \
"# text/parityfec\n" \
"text/plain					txt text conf def list log in\n" \
"# text/prs.fallenstein.rst\n" \
"text/prs.lines.tag				dsc\n" \
"# text/vnd.radisys.msml-basic-layout\n" \
"# text/red\n" \
"# text/rfc822-headers\n" \
"text/richtext					rtx\n" \
"# text/rtf\n" \
"# text/rtp-enc-aescm128\n" \
"# text/rtx\n" \
"text/sgml					sgml sgm\n" \
"# text/t140\n" \
"text/tab-separated-values			tsv\n" \
"text/troff					t tr roff man me ms\n" \
"text/turtle					ttl\n" \
"# text/ulpfec\n" \
"text/uri-list					uri uris urls\n" \
"text/vcard					vcard\n" \
"# text/vnd.abc\n" \
"text/vnd.curl					curl\n" \
"text/vnd.curl.dcurl				dcurl\n" \
"text/vnd.curl.scurl				scurl\n" \
"text/vnd.curl.mcurl				mcurl\n" \
"# text/vnd.dmclientscript\n" \
"text/vnd.dvb.subtitle				sub\n" \
"# text/vnd.esmertec.theme-descriptor\n" \
"text/vnd.fly					fly\n" \
"text/vnd.fmi.flexstor				flx\n" \
"text/vnd.graphviz				gv\n" \
"text/vnd.in3d.3dml				3dml\n" \
"text/vnd.in3d.spot				spot\n" \
"# text/vnd.iptc.newsml\n" \
"# text/vnd.iptc.nitf\n" \
"# text/vnd.latex-z\n" \
"# text/vnd.motorola.reflex\n" \
"# text/vnd.ms-mediapackage\n" \
"# text/vnd.net2phone.commcenter.command\n" \
"# text/vnd.si.uricatalogue\n" \
"text/vnd.sun.j2me.app-descriptor		jad\n" \
"# text/vnd.trolltech.linguist\n" \
"# text/vnd.wap.si\n" \
"# text/vnd.wap.sl\n" \
"text/vnd.wap.wml				wml\n" \
"text/vnd.wap.wmlscript				wmls\n" \
"text/x-asm					s asm\n" \
"text/x-c					c cc cxx cpp h hh dic\n" \
"text/x-fortran					f for f77 f90\n" \
"text/x-java-source				java\n" \
"text/x-opml					opml\n" \
"text/x-pascal					p pas\n" \
"text/x-nfo					nfo\n" \
"text/x-setext					etx\n" \
"text/x-sfv					sfv\n" \
"text/x-uuencode					uu\n" \
"text/x-vcalendar				vcs\n" \
"text/x-vcard					vcf\n" \
"# text/xml\n" \
"# text/xml-external-parsed-entity\n" \
"# video/1d-interleaved-parityfec\n" \
"video/3gpp					3gp\n" \
"# video/3gpp-tt\n" \
"video/3gpp2					3g2\n" \
"# video/bmpeg\n" \
"# video/bt656\n" \
"# video/celb\n" \
"# video/dv\n" \
"# video/example\n" \
"video/h261					h261\n" \
"video/h263					h263\n" \
"# video/h263-1998\n" \
"# video/h263-2000\n" \
"video/h264					h264\n" \
"# video/h264-rcdo\n" \
"# video/h264-svc\n" \
"video/jpeg					jpgv\n" \
"# video/jpeg2000\n" \
"video/jpm					jpm jpgm\n" \
"video/mj2					mj2 mjp2\n" \
"# video/mp1s\n" \
"# video/mp2p\n" \
"# video/mp2t\n" \
"video/mp4					mp4 mp4v mpg4\n" \
"# video/mp4v-es\n" \
"video/mpeg					mpeg mpg mpe m1v m2v\n" \
"# video/mpeg4-generic\n" \
"# video/mpv\n" \
"# video/nv\n" \
"video/ogg					ogv\n" \
"# video/parityfec\n" \
"# video/pointer\n" \
"video/quicktime					qt mov\n" \
"# video/raw\n" \
"# video/rtp-enc-aescm128\n" \
"# video/rtx\n" \
"# video/smpte292m\n" \
"# video/ulpfec\n" \
"# video/vc1\n" \
"# video/vnd.cctv\n" \
"video/vnd.dece.hd				uvh uvvh\n" \
"video/vnd.dece.mobile				uvm uvvm\n" \
"# video/vnd.dece.mp4\n" \
"video/vnd.dece.pd				uvp uvvp\n" \
"video/vnd.dece.sd				uvs uvvs\n" \
"video/vnd.dece.video				uvv uvvv\n" \
"# video/vnd.directv.mpeg\n" \
"# video/vnd.directv.mpeg-tts\n" \
"# video/vnd.dlna.mpeg-tts\n" \
"video/vnd.dvb.file				dvb\n" \
"video/vnd.fvt					fvt\n" \
"# video/vnd.hns.video\n" \
"# video/vnd.iptvforum.1dparityfec-1010\n" \
"# video/vnd.iptvforum.1dparityfec-2005\n" \
"# video/vnd.iptvforum.2dparityfec-1010\n" \
"# video/vnd.iptvforum.2dparityfec-2005\n" \
"# video/vnd.iptvforum.ttsavc\n" \
"# video/vnd.iptvforum.ttsmpeg2\n" \
"# video/vnd.motorola.video\n" \
"# video/vnd.motorola.videop\n" \
"video/vnd.mpegurl				mxu m4u\n" \
"video/vnd.ms-playready.media.pyv		pyv\n" \
"# video/vnd.nokia.interleaved-multimedia\n" \
"# video/vnd.nokia.videovoip\n" \
"# video/vnd.objectvideo\n" \
"# video/vnd.sealed.mpeg1\n" \
"# video/vnd.sealed.mpeg4\n" \
"# video/vnd.sealed.swf\n" \
"# video/vnd.sealedmedia.softseal.mov\n" \
"video/vnd.uvvu.mp4				uvu uvvu\n" \
"video/vnd.vivo					viv\n" \
"video/webm					webm\n" \
"video/x-f4v					f4v\n" \
"video/x-fli					fli\n" \
"video/x-flv					flv\n" \
"video/x-m4v					m4v\n" \
"video/x-matroska				mkv mk3d mks\n" \
"video/x-mng					mng\n" \
"video/x-ms-asf					asf asx\n" \
"video/x-ms-vob					vob\n" \
"video/x-ms-wm					wm\n" \
"video/x-ms-wmv					wmv\n" \
"video/x-ms-wmx					wmx\n" \
"video/x-ms-wvx					wvx\n" \
"video/x-msvideo					avi\n" \
"video/x-sgi-movie				movie\n" \
"video/x-smv					smv\n" \
"x-conference/x-cooltalk				ice\n";

static std::map<std::string,Poco::Net::MediaType> createDefaultApacheMap()
{
    std::istringstream iss(apacheMimeTypes);
    return MediaTypeMap::parse(iss);
}

static std::map<std::string,Poco::Net::MediaType> defaultMediaTypeMap = createDefaultApacheMap();


} } // namespace ofx::Media
