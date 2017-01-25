//
// Copyright (c) 2009 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofx/MediaTypeMap.h"
#include "ofFileUtils.h"
#include "Poco/UTF8String.h"
#include "ofxMediaType.h"

namespace ofx {

const std::string MediaTypeMap::DEFAULT_MEDIA_TYPE = "application/octet-stream";
const std::string MediaTypeMap::DEFAULT_APACHE_MIME_TYPES_PATH = "media/mime.types";
const std::string MediaTypeMap::DEFAULT_FILE_EXTENSION = "bin";
const std::string MediaTypeMap::DEFAULT_MINIMAL_APACHE_MIME_TYPES = 
"\
application/andrew-inset			ez\n \
application/applixware				aw\n \
application/atom+xml				atom\n \
application/atomcat+xml				atomcat\n \
application/atomsvc+xml				atomsvc\n \
application/ccxml+xml				ccxml\n \
application/cdmi-capability			cdmia\n \
application/cdmi-container			cdmic\n \
application/cdmi-domain				cdmid\n \
application/cdmi-object				cdmio\n \
application/cdmi-queue				cdmiq\n \
application/cu-seeme				cu\n \
application/davmount+xml			davmount\n \
application/docbook+xml				dbk\n \
application/dssc+der				dssc\n \
application/dssc+xml				xdssc\n \
application/ecmascript				ecma\n \
application/emma+xml				emma\n \
application/epub+zip				epub\n \
application/exi					exi\n \
application/font-tdpfr				pfr\n \
application/font-woff				woff\n \
application/gml+xml				gml\n \
application/gpx+xml				gpx\n \
application/gxf					gxf\n \
application/hyperstudio				stk\n \
application/inkml+xml				ink inkml\n \
application/ipfix				ipfix\n \
application/java-archive			jar\n \
application/java-serialized-object		ser\n \
application/java-vm				class\n \
application/javascript				js\n \
application/json				json\n \
application/jsonml+json				jsonml\n \
application/lost+xml				lostxml\n \
application/mac-binhex40			hqx\n \
application/mac-compactpro			cpt\n \
application/mads+xml				mads\n \
application/marc				mrc\n \
application/marcxml+xml				mrcx\n \
application/mathematica				ma nb mb\n \
application/mathml+xml				mathml\n \
application/mbox				mbox\n \
application/mediaservercontrol+xml		mscml\n \
application/metalink+xml			metalink\n \
application/metalink4+xml			meta4\n \
application/mets+xml				mets\n \
application/mods+xml				mods\n \
application/mp21				m21 mp21\n \
application/mp4					mp4s\n \
application/msword				doc dot\n \
application/mxf					mxf\n \
application/octet-stream	bin dms lrf mar so dist distz pkg bpk dump elc deploy\n \
application/oda					oda\n \
application/oebps-package+xml			opf\n \
application/ogg					ogx\n \
application/omdoc+xml				omdoc\n \
application/onenote				onetoc onetoc2 onetmp onepkg\n \
application/oxps				oxps\n \
application/patch-ops-error+xml			xer\n \
application/pdf					pdf\n \
application/pgp-encrypted			pgp\n \
application/pgp-signature			asc sig\n \
application/pics-rules				prf\n \
application/pkcs10				p10\n \
application/pkcs7-mime				p7m p7c\n \
application/pkcs7-signature			p7s\n \
application/pkcs8				p8\n \
application/pkix-attr-cert			ac\n \
application/pkix-cert				cer\n \
application/pkix-crl				crl\n \
application/pkix-pkipath			pkipath\n \
application/pkixcmp				pki\n \
application/pls+xml				pls\n \
application/postscript				ai eps ps\n \
application/prs.cww				cww\n \
application/pskc+xml				pskcxml\n \
application/rdf+xml				rdf\n \
application/reginfo+xml				rif\n \
application/relax-ng-compact-syntax		rnc\n \
application/resource-lists+xml			rl\n \
application/resource-lists-diff+xml		rld\n \
application/rls-services+xml			rs\n \
application/rpki-ghostbusters			gbr\n \
application/rpki-manifest			mft\n \
application/rpki-roa				roa\n \
application/rsd+xml				rsd\n \
application/rss+xml				rss\n \
application/rtf					rtf\n \
application/sbml+xml				sbml\n \
application/scvp-cv-request			scq\n \
application/scvp-cv-response			scs\n \
application/scvp-vp-request			spq\n \
application/scvp-vp-response			spp\n \
application/sdp					sdp\n \
application/set-payment-initiation		setpay\n \
application/set-registration-initiation		setreg\n \
application/shf+xml				shf\n \
application/smil+xml				smi smil\n \
application/sparql-query			rq\n \
application/sparql-results+xml			srx\n \
application/srgs				gram\n \
application/srgs+xml				grxml\n \
application/sru+xml				sru\n \
application/ssdl+xml				ssdl\n \
application/ssml+xml				ssml\n \
application/tei+xml				tei teicorpus\n \
application/thraud+xml				tfi\n \
application/timestamped-data			tsd\n \
application/vnd.3gpp.pic-bw-large		plb\n \
application/vnd.3gpp.pic-bw-small		psb\n \
application/vnd.3gpp.pic-bw-var			pvb\n \
application/vnd.3gpp2.tcap			tcap\n \
application/vnd.3m.post-it-notes		pwn\n \
application/vnd.accpac.simply.aso		aso\n \
application/vnd.accpac.simply.imp		imp\n \
application/vnd.acucobol			acu\n \
application/vnd.acucorp				atc acutc\n \
application/vnd.adobe.air-application-installer-package+zip	air\n \
application/vnd.adobe.formscentral.fcdt		fcdt\n \
application/vnd.adobe.fxp			fxp fxpl\n \
application/vnd.adobe.xdp+xml			xdp\n \
application/vnd.adobe.xfdf			xfdf\n \
application/vnd.ahead.space			ahead\n \
application/vnd.airzip.filesecure.azf		azf\n \
application/vnd.airzip.filesecure.azs		azs\n \
application/vnd.amazon.ebook			azw\n \
application/vnd.americandynamics.acc		acc\n \
application/vnd.amiga.ami			ami\n \
application/vnd.android.package-archive		apk\n \
application/vnd.anser-web-certificate-issue-initiation	cii\n \
application/vnd.anser-web-funds-transfer-initiation	fti\n \
application/vnd.antix.game-component		atx\n \
application/vnd.apple.installer+xml		mpkg\n \
application/vnd.apple.mpegurl			m3u8\n \
application/vnd.aristanetworks.swi		swi\n \
application/vnd.astraea-software.iota		iota\n \
application/vnd.audiograph			aep\n \
application/vnd.blueice.multipass		mpm\n \
application/vnd.bmi				bmi\n \
application/vnd.businessobjects			rep\n \
application/vnd.chemdraw+xml			cdxml\n \
application/vnd.chipnuts.karaoke-mmd		mmd\n \
application/vnd.cinderella			cdy\n \
application/vnd.claymore			cla\n \
application/vnd.cloanto.rp9			rp9\n \
application/vnd.clonk.c4group			c4g c4d c4f c4p c4u\n \
application/vnd.cluetrust.cartomobile-config		c11amc\n \
application/vnd.cluetrust.cartomobile-config-pkg	c11amz\n \
application/vnd.commonspace			csp\n \
application/vnd.contact.cmsg			cdbcmsg\n \
application/vnd.cosmocaller			cmc\n \
application/vnd.crick.clicker			clkx\n \
application/vnd.crick.clicker.keyboard		clkk\n \
application/vnd.crick.clicker.palette		clkp\n \
application/vnd.crick.clicker.template		clkt\n \
application/vnd.crick.clicker.wordbank		clkw\n \
application/vnd.criticaltools.wbs+xml		wbs\n \
application/vnd.ctc-posml			pml\n \
application/vnd.cups-ppd			ppd\n \
application/vnd.curl.car			car\n \
application/vnd.curl.pcurl			pcurl\n \
application/vnd.dart				dart\n \
application/vnd.data-vision.rdz			rdz\n \
application/vnd.dece.data			uvf uvvf uvd uvvd\n \
application/vnd.dece.ttml+xml			uvt uvvt\n \
application/vnd.dece.unspecified		uvx uvvx\n \
application/vnd.dece.zip			uvz uvvz\n \
application/vnd.denovo.fcselayout-link		fe_launch\n \
application/vnd.dna				dna\n \
application/vnd.dolby.mlp			mlp\n \
application/vnd.dpgraph				dpg\n \
application/vnd.dreamfactory			dfac\n \
application/vnd.ds-keypoint			kpxx\n \
application/vnd.dvb.ait				ait\n \
application/vnd.dvb.service			svc\n \
application/vnd.dynageo				geo\n \
application/vnd.ecowin.chart			mag\n \
application/vnd.enliven				nml\n \
application/vnd.epson.esf			esf\n \
application/vnd.epson.msf			msf\n \
application/vnd.epson.quickanime		qam\n \
application/vnd.epson.salt			slt\n \
application/vnd.epson.ssf			ssf\n \
application/vnd.eszigno3+xml			es3 et3\n \
application/vnd.ezpix-album			ez2\n \
application/vnd.ezpix-package			ez3\n \
application/vnd.fdf				fdf\n \
application/vnd.fdsn.mseed			mseed\n \
application/vnd.fdsn.seed			seed dataless\n \
application/vnd.flographit			gph\n \
application/vnd.fluxtime.clip			ftc\n \
application/vnd.framemaker			fm frame maker book\n \
application/vnd.frogans.fnc			fnc\n \
application/vnd.frogans.ltf			ltf\n \
application/vnd.fsc.weblaunch			fsc\n \
application/vnd.fujitsu.oasys			oas\n \
application/vnd.fujitsu.oasys2			oa2\n \
application/vnd.fujitsu.oasys3			oa3\n \
application/vnd.fujitsu.oasysgp			fg5\n \
application/vnd.fujitsu.oasysprs		bh2\n \
application/vnd.fujixerox.ddd			ddd\n \
application/vnd.fujixerox.docuworks		xdw\n \
application/vnd.fujixerox.docuworks.binder	xbd\n \
application/vnd.fuzzysheet			fzs\n \
application/vnd.genomatix.tuxedo		txd\n \
application/vnd.geogebra.file			ggb\n \
application/vnd.geogebra.tool			ggt\n \
application/vnd.geometry-explorer		gex gre\n \
application/vnd.geonext				gxt\n \
application/vnd.geoplan				g2w\n \
application/vnd.geospace			g3w\n \
application/vnd.gmx				gmx\n \
application/vnd.google-earth.kml+xml		kml\n \
application/vnd.google-earth.kmz		kmz\n \
application/vnd.grafeq				gqf gqs\n \
application/vnd.groove-account			gac\n \
application/vnd.groove-help			ghf\n \
application/vnd.groove-identity-message		gim\n \
application/vnd.groove-injector			grv\n \
application/vnd.groove-tool-message		gtm\n \
application/vnd.groove-tool-template		tpl\n \
application/vnd.groove-vcard			vcg\n \
application/vnd.hal+xml				hal\n \
application/vnd.handheld-entertainment+xml	zmm\n \
application/vnd.hbci				hbci\n \
application/vnd.hhe.lesson-player		les\n \
application/vnd.hp-hpgl				hpgl\n \
application/vnd.hp-hpid				hpid\n \
application/vnd.hp-hps				hps\n \
application/vnd.hp-jlyt				jlt\n \
application/vnd.hp-pcl				pcl\n \
application/vnd.hp-pclxl			pclxl\n \
application/vnd.hydrostatix.sof-data		sfd-hdstx\n \
application/vnd.ibm.minipay			mpy\n \
application/vnd.ibm.modcap			afp listafp list3820\n \
application/vnd.ibm.rights-management		irm\n \
application/vnd.ibm.secure-container		sc\n \
application/vnd.iccprofile			icc icm\n \
application/vnd.igloader			igl\n \
application/vnd.immervision-ivp			ivp\n \
application/vnd.immervision-ivu			ivu\n \
application/vnd.insors.igm			igm\n \
application/vnd.intercon.formnet		xpw xpx\n \
application/vnd.intergeo			i2g\n \
application/vnd.intu.qbo			qbo\n \
application/vnd.intu.qfx			qfx\n \
application/vnd.ipunplugged.rcprofile		rcprofile\n \
application/vnd.irepository.package+xml		irp\n \
application/vnd.is-xpr				xpr\n \
application/vnd.isac.fcs			fcs\n \
application/vnd.jam				jam\n \
application/vnd.jcp.javame.midlet-rms		rms\n \
application/vnd.jisp				jisp\n \
application/vnd.joost.joda-archive		joda\n \
application/vnd.kahootz				ktz ktr\n \
application/vnd.kde.karbon			karbon\n \
application/vnd.kde.kchart			chrt\n \
application/vnd.kde.kformula			kfo\n \
application/vnd.kde.kivio			flw\n \
application/vnd.kde.kontour			kon\n \
application/vnd.kde.kpresenter			kpr kpt\n \
application/vnd.kde.kspread			ksp\n \
application/vnd.kde.kword			kwd kwt\n \
application/vnd.kenameaapp			htke\n \
application/vnd.kidspiration			kia\n \
application/vnd.kinar				kne knp\n \
application/vnd.koan				skp skd skt skm\n \
application/vnd.kodak-descriptor		sse\n \
application/vnd.las.las+xml			lasxml\n \
application/vnd.llamagraphics.life-balance.desktop	lbd\n \
application/vnd.llamagraphics.life-balance.exchange+xml	lbe\n \
application/vnd.lotus-1-2-3			123\n \
application/vnd.lotus-approach			apr\n \
application/vnd.lotus-freelance			pre\n \
application/vnd.lotus-notes			nsf\n \
application/vnd.lotus-organizer			org\n \
application/vnd.lotus-screencam			scm\n \
application/vnd.lotus-wordpro			lwp\n \
application/vnd.macports.portpkg		portpkg\n \
application/vnd.mcd				mcd\n \
application/vnd.medcalcdata			mc1\n \
application/vnd.mediastation.cdkey		cdkey\n \
application/vnd.mfer				mwf\n \
application/vnd.mfmp				mfm\n \
application/vnd.micrografx.flo			flo\n \
application/vnd.micrografx.igx			igx\n \
application/vnd.mif				mif\n \
application/vnd.mobius.daf			daf\n \
application/vnd.mobius.dis			dis\n \
application/vnd.mobius.mbk			mbk\n \
application/vnd.mobius.mqy			mqy\n \
application/vnd.mobius.msl			msl\n \
application/vnd.mobius.plc			plc\n \
application/vnd.mobius.txf			txf\n \
application/vnd.mophun.application		mpn\n \
application/vnd.mophun.certificate		mpc\n \
application/vnd.mozilla.xul+xml			xul\n \
application/vnd.ms-artgalry			cil\n \
application/vnd.ms-cab-compressed		cab\n \
application/vnd.ms-excel			xls xlm xla xlc xlt xlw\n \
application/vnd.ms-excel.addin.macroenabled.12		xlam\n \
application/vnd.ms-excel.sheet.binary.macroenabled.12	xlsb\n \
application/vnd.ms-excel.sheet.macroenabled.12		xlsm\n \
application/vnd.ms-excel.template.macroenabled.12	xltm\n \
application/vnd.ms-fontobject			eot\n \
application/vnd.ms-htmlhelp			chm\n \
application/vnd.ms-ims				ims\n \
application/vnd.ms-lrm				lrm\n \
application/vnd.ms-officetheme			thmx\n \
application/vnd.ms-pki.seccat			cat\n \
application/vnd.ms-pki.stl			stl\n \
application/vnd.ms-powerpoint			ppt pps pot\n \
application/vnd.ms-powerpoint.addin.macroenabled.12		ppam\n \
application/vnd.ms-powerpoint.presentation.macroenabled.12	pptm\n \
application/vnd.ms-powerpoint.slide.macroenabled.12		sldm\n \
application/vnd.ms-powerpoint.slideshow.macroenabled.12		ppsm\n \
application/vnd.ms-powerpoint.template.macroenabled.12		potm\n \
application/vnd.ms-project			mpp mpt\n \
application/vnd.ms-word.document.macroenabled.12	docm\n \
application/vnd.ms-word.template.macroenabled.12	dotm\n \
application/vnd.ms-works			wps wks wcm wdb\n \
application/vnd.ms-wpl				wpl\n \
application/vnd.ms-xpsdocument			xps\n \
application/vnd.mseq				mseq\n \
application/vnd.musician			mus\n \
application/vnd.muvee.style			msty\n \
application/vnd.mynfc				taglet\n \
application/vnd.neurolanguage.nlu		nlu\n \
application/vnd.nitf				ntf nitf\n \
application/vnd.noblenet-directory		nnd\n \
application/vnd.noblenet-sealer			nns\n \
application/vnd.noblenet-web			nnw\n \
application/vnd.nokia.n-gage.data		ngdat\n \
application/vnd.nokia.n-gage.symbian.install	n-gage\n \
application/vnd.nokia.radio-preset		rpst\n \
application/vnd.nokia.radio-presets		rpss\n \
application/vnd.novadigm.edm			edm\n \
application/vnd.novadigm.edx			edx\n \
application/vnd.novadigm.ext			ext\n \
application/vnd.oasis.opendocument.chart		odc\n \
application/vnd.oasis.opendocument.chart-template	otc\n \
application/vnd.oasis.opendocument.database		odb\n \
application/vnd.oasis.opendocument.formula		odf\n \
application/vnd.oasis.opendocument.formula-template	odft\n \
application/vnd.oasis.opendocument.graphics		odg\n \
application/vnd.oasis.opendocument.graphics-template	otg\n \
application/vnd.oasis.opendocument.image		odi\n \
application/vnd.oasis.opendocument.image-template	oti\n \
application/vnd.oasis.opendocument.presentation		odp\n \
application/vnd.oasis.opendocument.presentation-template	otp\n \
application/vnd.oasis.opendocument.spreadsheet		ods\n \
application/vnd.oasis.opendocument.spreadsheet-template	ots\n \
application/vnd.oasis.opendocument.text			odt\n \
application/vnd.oasis.opendocument.text-master		odm\n \
application/vnd.oasis.opendocument.text-template	ott\n \
application/vnd.oasis.opendocument.text-web		oth\n \
application/vnd.olpc-sugar			xo\n \
application/vnd.oma.dd2+xml			dd2\n \
application/vnd.openofficeorg.extension		oxt\n \
application/vnd.openxmlformats-officedocument.presentationml.presentation	pptx\n \
application/vnd.openxmlformats-officedocument.presentationml.slide	sldx\n \
application/vnd.openxmlformats-officedocument.presentationml.slideshow	ppsx\n \
application/vnd.openxmlformats-officedocument.presentationml.template	potx\n \
application/vnd.openxmlformats-officedocument.spreadsheetml.sheet	xlsx\n \
application/vnd.openxmlformats-officedocument.spreadsheetml.template	xltx\n \
application/vnd.openxmlformats-officedocument.wordprocessingml.document	docx\n \
application/vnd.openxmlformats-officedocument.wordprocessingml.template	dotx\n \
application/vnd.osgeo.mapguide.package		mgp\n \
application/vnd.osgi.dp				dp\n \
application/vnd.osgi.subsystem			esa\n \
application/vnd.palm				pdb pqa oprc\n \
application/vnd.pawaafile			paw\n \
application/vnd.pg.format			str\n \
application/vnd.pg.osasli			ei6\n \
application/vnd.picsel				efif\n \
application/vnd.pmi.widget			wg\n \
application/vnd.pocketlearn			plf\n \
application/vnd.powerbuilder6			pbd\n \
application/vnd.previewsystems.box		box\n \
application/vnd.proteus.magazine		mgz\n \
application/vnd.publishare-delta-tree		qps\n \
application/vnd.pvi.ptid1			ptid\n \
application/vnd.quark.quarkxpress		qxd qxt qwd qwt qxl qxb\n \
application/vnd.realvnc.bed			bed\n \
application/vnd.recordare.musicxml		mxl\n \
application/vnd.recordare.musicxml+xml		musicxml\n \
application/vnd.rig.cryptonote			cryptonote\n \
application/vnd.rim.cod				cod\n \
application/vnd.rn-realmedia			rm\n \
application/vnd.rn-realmedia-vbr		rmvb\n \
application/vnd.route66.link66+xml		link66\n \
application/vnd.sailingtracker.track		st\n \
application/vnd.seemail				see\n \
application/vnd.sema				sema\n \
application/vnd.semd				semd\n \
application/vnd.semf				semf\n \
application/vnd.shana.informed.formdata		ifm\n \
application/vnd.shana.informed.formtemplate	itp\n \
application/vnd.shana.informed.interchange	iif\n \
application/vnd.shana.informed.package		ipk\n \
application/vnd.simtech-mindmapper		twd twds\n \
application/vnd.smaf				mmf\n \
application/vnd.smart.teacher			teacher\n \
application/vnd.solent.sdkm+xml			sdkm sdkd\n \
application/vnd.spotfire.dxp			dxp\n \
application/vnd.spotfire.sfs			sfs\n \
application/vnd.stardivision.calc		sdc\n \
application/vnd.stardivision.draw		sda\n \
application/vnd.stardivision.impress		sdd\n \
application/vnd.stardivision.math		smf\n \
application/vnd.stardivision.writer		sdw vor\n \
application/vnd.stardivision.writer-global	sgl\n \
application/vnd.stepmania.package		smzip\n \
application/vnd.stepmania.stepchart		sm\n \
application/vnd.sun.xml.calc			sxc\n \
application/vnd.sun.xml.calc.template		stc\n \
application/vnd.sun.xml.draw			sxd\n \
application/vnd.sun.xml.draw.template		std\n \
application/vnd.sun.xml.impress			sxi\n \
application/vnd.sun.xml.impress.template	sti\n \
application/vnd.sun.xml.math			sxm\n "
"application/vnd.sun.xml.writer			sxw\n \
application/vnd.sun.xml.writer.global		sxg\n \
application/vnd.sun.xml.writer.template		stw\n \
application/vnd.sus-calendar			sus susp\n \
application/vnd.svd				svd\n \
application/vnd.symbian.install			sis sisx\n \
application/vnd.syncml+xml			xsm\n \
application/vnd.syncml.dm+wbxml			bdm\n \
application/vnd.syncml.dm+xml			xdm\n \
application/vnd.tao.intent-module-archive	tao\n \
application/vnd.tcpdump.pcap			pcap cap dmp\n \
application/vnd.tmobile-livetv			tmo\n \
application/vnd.trid.tpt			tpt\n \
application/vnd.triscape.mxs			mxs\n \
application/vnd.trueapp				tra\n \
application/vnd.ufdl				ufd ufdl\n \
application/vnd.uiq.theme			utz\n \
application/vnd.umajin				umj\n \
application/vnd.unity				unityweb\n \
application/vnd.uoml+xml			uoml\n \
application/vnd.vcx				vcx\n \
application/vnd.visio				vsd vst vss vsw\n \
application/vnd.visionary			vis\n \
application/vnd.vsf				vsf\n \
application/vnd.wap.wbxml			wbxml\n \
application/vnd.wap.wmlc			wmlc\n \
application/vnd.wap.wmlscriptc			wmlsc\n \
application/vnd.webturbo			wtb\n \
application/vnd.wolfram.player			nbp\n \
application/vnd.wordperfect			wpd\n \
application/vnd.wqd				wqd\n \
application/vnd.wt.stf				stf\n \
application/vnd.xara				xar\n \
application/vnd.xfdl				xfdl\n \
application/vnd.yamaha.hv-dic			hvd\n \
application/vnd.yamaha.hv-script		hvs\n \
application/vnd.yamaha.hv-voice			hvp\n \
application/vnd.yamaha.openscoreformat			osf\n \
application/vnd.yamaha.openscoreformat.osfpvg+xml	osfpvg\n \
application/vnd.yamaha.smaf-audio		saf\n \
application/vnd.yamaha.smaf-phrase		spf\n \
application/vnd.yellowriver-custom-menu		cmp\n \
application/vnd.zul				zir zirz\n \
application/vnd.zzazz.deck+xml			zaz\n \
application/voicexml+xml			vxml\n \
application/widget				wgt\n \
application/winhlp				hlp\n \
application/wsdl+xml				wsdl\n \
application/wspolicy+xml			wspolicy\n \
application/x-7z-compressed			7z\n \
application/x-abiword				abw\n \
application/x-ace-compressed			ace\n \
application/x-apple-diskimage			dmg\n \
application/x-authorware-bin			aab x32 u32 vox\n \
application/x-authorware-map			aam\n \
application/x-authorware-seg			aas\n \
application/x-bcpio				bcpio\n \
application/x-bittorrent			torrent\n \
application/x-blorb				blb blorb\n \
application/x-bzip				bz\n \
application/x-bzip2				bz2 boz\n \
application/x-cbr				cbr cba cbt cbz cb7\n \
application/x-cdlink				vcd\n \
application/x-cfs-compressed			cfs\n \
application/x-chat				chat\n \
application/x-chess-pgn				pgn\n \
application/x-conference			nsc\n \
application/x-cpio				cpio\n \
application/x-csh				csh\n \
application/x-debian-package			deb udeb\n \
application/x-dgc-compressed			dgc\n \
application/x-director			dir dcr dxr cst cct cxt w3d fgd swa\n \
application/x-doom				wad\n \
application/x-dtbncx+xml			ncx\n \
application/x-dtbook+xml			dtb\n \
application/x-dtbresource+xml			res\n \
application/x-dvi				dvi\n \
application/x-envoy				evy\n \
application/x-eva				eva\n \
application/x-font-bdf				bdf\n \
application/x-font-ghostscript			gsf\n \
application/x-font-linux-psf			psf\n \
application/x-font-otf				otf\n \
application/x-font-pcf				pcf\n \
application/x-font-snf				snf\n \
application/x-font-ttf				ttf ttc\n \
application/x-font-type1			pfa pfb pfm afm\n \
application/x-freearc				arc\n \
application/x-futuresplash			spl\n \
application/x-gca-compressed			gca\n \
application/x-glulx				ulx\n \
application/x-gnumeric				gnumeric\n \
application/x-gramps-xml			gramps\n \
application/x-gtar				gtar\n \
application/x-hdf				hdf\n \
application/x-install-instructions		install\n \
application/x-iso9660-image			iso\n \
application/x-java-jnlp-file			jnlp\n \
application/x-latex				latex\n \
application/x-lzh-compressed			lzh lha\n \
application/x-mie				mie\n \
application/x-mobipocket-ebook			prc mobi\n \
application/x-ms-application			application\n \
application/x-ms-shortcut			lnk\n \
application/x-ms-wmd				wmd\n \
application/x-ms-wmz				wmz\n \
application/x-ms-xbap				xbap\n \
application/x-msaccess				mdb\n \
application/x-msbinder				obd\n \
application/x-mscardfile			crd\n \
application/x-msclip				clp\n \
application/x-msdownload			exe dll com bat msi\n \
application/x-msmediaview			mvb m13 m14\n \
application/x-msmetafile			wmf wmz emf emz\n \
application/x-msmoney				mny\n \
application/x-mspublisher			pub\n \
application/x-msschedule			scd\n \
application/x-msterminal			trm\n \
application/x-mswrite				wri\n \
application/x-netcdf				nc cdf\n \
application/x-nzb				nzb\n \
application/x-pkcs12				p12 pfx\n \
application/x-pkcs7-certificates		p7b spc\n \
application/x-pkcs7-certreqresp			p7r\n \
application/x-rar-compressed			rar\n \
application/x-research-info-systems		ris\n \
application/x-sh				sh\n \
application/x-shar				shar\n \
application/x-shockwave-flash			swf\n \
application/x-silverlight-app			xap\n \
application/x-sql				sql\n \
application/x-stuffit				sit\n \
application/x-stuffitx				sitx\n \
application/x-subrip				srt\n \
application/x-sv4cpio				sv4cpio\n \
application/x-sv4crc				sv4crc\n \
application/x-t3vm-image			t3\n \
application/x-tads				gam\n \
application/x-tar				tar\n \
application/x-tcl				tcl\n \
application/x-tex				tex\n \
application/x-tex-tfm				tfm\n \
application/x-texinfo				texinfo texi\n \
application/x-tgif				obj\n \
application/x-ustar				ustar\n \
application/x-wais-source			src\n \
application/x-x509-ca-cert			der crt\n \
application/x-xfig				fig\n \
application/x-xliff+xml				xlf\n \
application/x-xpinstall				xpi\n \
application/x-xz				xz\n \
application/x-zmachine				z1 z2 z3 z4 z5 z6 z7 z8\n \
application/xaml+xml				xaml\n \
application/xcap-diff+xml			xdf\n \
application/xenc+xml				xenc\n \
application/xhtml+xml				xhtml xht\n \
application/xml					xml xsl\n \
application/xml-dtd				dtd\n \
application/xop+xml				xop\n \
application/xproc+xml				xpl\n \
application/xslt+xml				xslt\n \
application/xspf+xml				xspf\n \
application/xv+xml				mxml xhvml xvml xvm\n \
application/yang				yang\n \
application/yin+xml				yin\n \
application/zip					zip\n \
audio/adpcm					adp\n \
audio/basic					au snd\n \
audio/midi					mid midi kar rmi\n \
audio/mp4					m4a mp4a\n \
audio/mpeg					mpga mp2 mp2a mp3 m2a m3a\n \
audio/ogg					oga ogg spx\n \
audio/s3m					s3m\n \
audio/silk					sil\n \
audio/vnd.dece.audio				uva uvva\n \
audio/vnd.digital-winds				eol\n \
audio/vnd.dra					dra\n \
audio/vnd.dts					dts\n \
audio/vnd.dts.hd				dtshd\n \
audio/vnd.lucent.voice				lvp\n \
audio/vnd.ms-playready.media.pya		pya\n \
audio/vnd.nuera.ecelp4800			ecelp4800\n \
audio/vnd.nuera.ecelp7470			ecelp7470\n \
audio/vnd.nuera.ecelp9600			ecelp9600\n \
audio/vnd.rip					rip\n \
audio/webm					weba\n \
audio/x-aac					aac\n \
audio/x-aiff					aif aiff aifc\n \
audio/x-caf					caf\n \
audio/x-flac					flac\n \
audio/x-matroska				mka\n \
audio/x-mpegurl					m3u\n \
audio/x-ms-wax					wax\n \
audio/x-ms-wma					wma\n \
audio/x-pn-realaudio				ram ra\n \
audio/x-pn-realaudio-plugin			rmp\n \
audio/x-wav					wav\n \
audio/xm					xm\n \
chemical/x-cdx					cdx\n \
chemical/x-cif					cif\n \
chemical/x-cmdf					cmdf\n \
chemical/x-cml					cml\n \
chemical/x-csml					csml\n \
chemical/x-xyz					xyz\n \
image/bmp					bmp\n \
image/cgm					cgm\n \
image/g3fax					g3\n \
image/gif					gif\n \
image/ief					ief\n \
image/jpeg					jpeg jpg jpe\n \
image/ktx					ktx\n \
image/png					png\n \
image/prs.btif					btif\n \
image/sgi					sgi\n \
image/svg+xml					svg svgz\n \
image/tiff					tiff tif\n \
image/vnd.adobe.photoshop			psd\n \
image/vnd.dece.graphic				uvi uvvi uvg uvvg\n \
image/vnd.djvu					djvu djv\n \
image/vnd.dvb.subtitle				sub\n \
image/vnd.dwg					dwg\n \
image/vnd.dxf					dxf\n \
image/vnd.fastbidsheet				fbs\n \
image/vnd.fpx					fpx\n \
image/vnd.fst					fst\n \
image/vnd.fujixerox.edmics-mmr			mmr\n \
image/vnd.fujixerox.edmics-rlc			rlc\n \
image/vnd.ms-modi				mdi\n \
image/vnd.ms-photo				wdp\n \
image/vnd.net-fpx				npx\n \
image/vnd.wap.wbmp				wbmp\n \
image/vnd.xiff					xif\n \
image/webp					webp\n \
image/x-3ds					3ds\n \
image/x-cmu-raster				ras\n \
image/x-cmx					cmx\n \
image/x-freehand				fh fhc fh4 fh5 fh7\n \
image/x-icon					ico\n \
image/x-mrsid-image				sid\n \
image/x-pcx					pcx\n \
image/x-pict					pic pct\n \
image/x-portable-anymap				pnm\n \
image/x-portable-bitmap				pbm\n \
image/x-portable-graymap			pgm\n \
image/x-portable-pixmap				ppm\n \
image/x-rgb					rgb\n \
image/x-tga					tga\n \
image/x-xbitmap					xbm\n \
image/x-xpixmap					xpm\n \
image/x-xwindowdump				xwd\n \
message/rfc822					eml mime\n \
model/iges					igs iges\n \
model/mesh					msh mesh silo\n \
model/vnd.collada+xml				dae\n \
model/vnd.dwf					dwf\n \
model/vnd.gdl					gdl\n \
model/vnd.gtw					gtw\n \
model/vnd.mts					mts\n \
model/vnd.vtu					vtu\n \
model/vrml					wrl vrml\n \
model/x3d+binary				x3db x3dbz\n \
model/x3d+vrml					x3dv x3dvz\n \
model/x3d+xml					x3d x3dz\n \
text/cache-manifest				appcache\n \
text/calendar					ics ifb\n \
text/css					css\n \
text/csv					csv\n \
text/html					html htm\n \
text/n3						n3\n \
text/plain					txt text conf def list log in\n \
text/prs.lines.tag				dsc\n \
text/richtext					rtx\n \
text/sgml					sgml sgm\n \
text/tab-separated-values			tsv\n \
text/troff					t tr roff man me ms\n \
text/turtle					ttl\n \
text/uri-list					uri uris urls\n \
text/vcard					vcard\n \
text/vnd.curl					curl\n \
text/vnd.curl.dcurl				dcurl\n \
text/vnd.curl.mcurl				mcurl\n \
text/vnd.curl.scurl				scurl\n \
text/vnd.dvb.subtitle				sub\n \
text/vnd.fly					fly\n \
text/vnd.fmi.flexstor				flx\n \
text/vnd.graphviz				gv\n \
text/vnd.in3d.3dml				3dml\n \
text/vnd.in3d.spot				spot\n \
text/vnd.sun.j2me.app-descriptor		jad\n \
text/vnd.wap.wml				wml\n \
text/vnd.wap.wmlscript				wmls\n \
text/x-asm					s asm\n \
text/x-c					c cc cxx cpp h hh dic\n \
text/x-fortran					f for f77 f90\n \
text/x-java-source				java\n \
text/x-nfo					nfo\n \
text/x-opml					opml\n \
text/x-pascal					p pas\n \
text/x-setext					etx\n \
text/x-sfv					sfv\n \
text/x-uuencode					uu\n \
text/x-vcalendar				vcs\n \
text/x-vcard					vcf\n \
video/3gpp					3gp\n \
video/3gpp2					3g2\n \
video/h261					h261\n \
video/h263					h263\n \
video/h264					h264\n \
video/jpeg					jpgv\n \
video/jpm					jpm jpgm\n \
video/mj2					mj2 mjp2\n \
video/mp4					mp4 mp4v mpg4\n \
video/mpeg					mpeg mpg mpe m1v m2v\n \
video/ogg					ogv\n \
video/quicktime					qt mov\n \
video/vnd.dece.hd				uvh uvvh\n \
video/vnd.dece.mobile				uvm uvvm\n \
video/vnd.dece.pd				uvp uvvp\n \
video/vnd.dece.sd				uvs uvvs\n \
video/vnd.dece.video				uvv uvvv\n \
video/vnd.dvb.file				dvb\n \
video/vnd.fvt					fvt\n \
video/vnd.mpegurl				mxu m4u\n \
video/vnd.ms-playready.media.pyv		pyv\n \
video/vnd.uvvu.mp4				uvu uvvu\n \
video/vnd.vivo					viv\n \
video/webm					webm\n \
video/x-f4v					f4v\n \
video/x-fli					fli\n \
video/x-flv					flv\n \
video/x-m4v					m4v\n \
video/x-matroska				mkv mk3d mks\n \
video/x-mng					mng\n \
video/x-ms-asf					asf asx\n \
video/x-ms-vob					vob\n \
video/x-ms-wm					wm\n \
video/x-ms-wmv					wmv\n \
video/x-ms-wmx					wmx\n \
video/x-ms-wvx					wvx\n \
video/x-msvideo					avi\n \
video/x-sgi-movie				movie\n \
video/x-smv					smv\n \
x-conference/x-cooltalk				ice\n ";

MediaTypeMap::MediaTypeMap():
    MediaTypeMap(DEFAULT_APACHE_MIME_TYPES_PATH, DEFAULT_MEDIA_TYPE)
{
}


MediaTypeMap::MediaTypeMap(const std::string& mimeTypesFile):
    MediaTypeMap(mimeTypesFile, DEFAULT_MEDIA_TYPE)
{
}


MediaTypeMap::MediaTypeMap(const std::string& mimeTypesFile,
                           const std::string& defaultMediaType):
    _defaultMediaType(defaultMediaType)
{
    ofBuffer buffer = ofBufferFromFile(mimeTypesFile);

    if (0 == buffer.size())
    {
        ofLogVerbose("MediaTypeMap::MediaTypeMap") << "Mime types file not found, using defaults.";
        buffer.set(DEFAULT_MINIMAL_APACHE_MIME_TYPES);
    }

    std::stringstream ss;
    ss << buffer;
    load(ss);
}


MediaTypeMap::~MediaTypeMap()
{
}


Poco::Net::MediaType MediaTypeMap::getMediaTypeForPath(const Poco::Path& path) const
{
    Poco::File file(path);

    if (file.exists() && file.isDirectory())
    {
        return Poco::Net::MediaType("inode/directory");
    }
    else
    {
        FileExtensionConstIterator iter = _fileExtensionToMediaTypeMap.find(Poco::UTF8::toLower(path.getExtension()));

        if (iter != _fileExtensionToMediaTypeMap.end())
        {
            return (*iter).second;
        }
        else
        {
            return _defaultMediaType;
        }
    }
}


std::string MediaTypeMap::getMediaDescription(const Poco::Path& path,
                                              bool) const
{
    return getMediaTypeForPath(path).toString();
}


std::vector<std::string> MediaTypeMap::getFileExtensionsForMediaType(const Poco::Net::MediaType& mediaType) const
{
    std::vector<std::string> fileExtensions;

    MediaTypeConstIterator iter = _mediaTypeToFileExtensionMap.begin();

    while (iter != _mediaTypeToFileExtensionMap.end())
    {
        if (mediaType.matches(iter->first))
        {
            fileExtensions = iter->second;

            if (fileExtensions.empty())
            {
                fileExtensions.push_back(_defaultFileExtension);
                return fileExtensions;
            }
            else
            {
                return fileExtensions;
            }
        }

        ++iter;
    }

    fileExtensions.push_back(_defaultFileExtension);

    return fileExtensions;

}


std::string MediaTypeMap::getBestFileExtensionsForMediaType(const Poco::Net::MediaType& mediaType) const
{
    std::vector<std::string> fileExtensions = getFileExtensionsForMediaType(mediaType);

    if (fileExtensions.empty())
    {
        return _defaultFileExtension;
    }
    else
    {
        return fileExtensions[0];
    }
}


void MediaTypeMap::add(const std::string& suffix,
                       const Poco::Net::MediaType& mediaType)
{
    _fileExtensionToMediaTypeMap.insert(std::make_pair(suffix, mediaType.toString()));

    std::vector<std::string> fileExtensions = getFileExtensionsForMediaType(mediaType);

    std::vector<std::string>::iterator iter = fileExtensions.begin();

    while (iter != fileExtensions.end())
    {
        if (*iter == suffix) return; // Already exists.
        ++iter;
    }

    fileExtensions.push_back(suffix);

    _mediaTypeToFileExtensionMap.insert(std::make_pair(mediaType.toString(), fileExtensions));

}


bool MediaTypeMap::load(std::istream& inputStream)
{
    return parse(inputStream,
                 _fileExtensionToMediaTypeMap,
                 _mediaTypeToFileExtensionMap);
}


void MediaTypeMap::clear()
{
    _mediaTypeToFileExtensionMap.clear();
    _fileExtensionToMediaTypeMap.clear();
}


Poco::Net::MediaType MediaTypeMap::getDefaultMediaType() const
{
    return _defaultMediaType;
}


void MediaTypeMap::setDefaultMediaType(const Poco::Net::MediaType& defaultMediaType)
{
    _defaultMediaType = defaultMediaType;
}


std::string MediaTypeMap::getDefaultFileExtension() const
{
    return _defaultFileExtension;
}


void MediaTypeMap::setDefaultFileExtension(const std::string& defaultFileExtension)
{
    _defaultFileExtension = defaultFileExtension;
}


std::shared_ptr<MediaTypeMap> MediaTypeMap::getDefault()
{
    static std::shared_ptr<MediaTypeMap> ptr = std::make_shared<MediaTypeMap>();
    return ptr;
}


bool MediaTypeMap::parse(std::istream& inputStream,
                         FileExtensionToMediaTypeMap& fileExtensionToMediaTypeMap,
                         MediaTypeToFileExtensionMap& mediaTypeToFileExtensionMap)
{
    fileExtensionToMediaTypeMap.clear();
    mediaTypeToFileExtensionMap.clear();

    std::string line;

    while (std::getline(inputStream, line))
    {
        Poco::trimInPlace(line);
        Poco::replaceInPlace(line, "\t", " ");

        if (line.empty() || '#' == line[0]) continue;

        int tokenizerFlags = Poco::StringTokenizer::TOK_TRIM |
                             Poco::StringTokenizer::TOK_IGNORE_EMPTY;

        
        Poco::StringTokenizer tokens(line, " ", tokenizerFlags);

        if (tokens.count() > 1)
        {
            std::string mediaType;;
            std::vector<std::string> fileExtensions;

            auto iter = tokens.begin();

            while (iter != tokens.end())
            {
                if (iter == tokens.begin())
                {
                    mediaType = *iter;
                }
                else
                {
                    fileExtensions.push_back(*iter);
                    fileExtensionToMediaTypeMap.insert(std::make_pair(*iter,
                                                                      mediaType));
                }

                ++iter;
            }

            mediaTypeToFileExtensionMap.insert(std::make_pair(mediaType, fileExtensions));
        }
        else
        {
            ofLogVerbose("MediaTypeMap::parse") << "Parse error on line: " << line;
        }
    }
    
    return true;
}


} // namespace ofx
