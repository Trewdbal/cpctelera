![CPCtelera Logo](https://github.com/lronaldo/cpctelera/blob/master/cpctelera/docs/images/cpct_logo.png)

_**Astonishing fast Amstrad CPC game engine for C developers**_

---------------------------------------------------------------

_**CPCtelera**_ is a game engine for Amstrad CPC computers whose aim is to have the fastest possible 
routines to aid developers in the creation of games. The main aims of _**CPCtelera**_ are producing the fastest possible code, being very easy to install and use in every modern platform and having an extensively commented code, to aid those wanting to learn from code.

**Installing and using** _**CPCtelera**_ is very easy: 
 * [How to install CPCtelera](http://lronaldo.github.io/cpctelera/files/readme-txt.html#Installing_CPCtelera)
 * [CPCtelera reference manual](http://lronaldo.github.io/cpctelera) 
 
If you are a Mac user, you will want to consider installing [CPCtelera-samples-Xcode](https://github.com/dfreniche/cpctelera_samples_xcode) by [Diego Freniche](http://blog.freniche.com), along with _**CPCtelera**_. This package creates Xcode projects from examples and lets you build them directly from Xcode.

### Supported Platforms

_**CPCtelera**_ is fully usable and has been tested under these platforms:
 * Windows (with Cygwin 32/64 bits)
 * OS X
 * Linux (Ubuntu/Debian, Raspbian, Arch and Manjaro)

If you test it in any platform (listed here or not) and have problems, please feel free to report them to us. 

### Contact information and support

If you have any questions, please contact us:

 * email:    _cpctelera (at) cheesetea (dot) com_
 * twitter:  *[@FranGallegoBR](http://twitter.com/frangallegobr)*

### Authors

 * **Project owner** 
   * [ronaldo](http://twitter.com/frangallegobr) / ([Cheesetea](http://www.cheesetea.com), [Fremos](http://fremos.cheesetea.com),  [ByteRealms](http://www.byterealms.com))
 * **Awesome collaborators**
   * [Dardalorth](http://lalunadedardalorth.blogspot.com.es/) / [Fremos](http://fremos.cheesetea.com) / [Carlio](http://carlio.es)
   * Stefano Beltran / [ByteRealms](http://www.byterealms.com) 
   * [Fran Fernández](https://twitter.com/ronsonmaria) / [Pensando como Pollos](http://www.pensandocomopollos.com/) ([@ronsonmaria](https://twitter.com/ronsonmaria))
   * [Diego Freniche](http://blog.freniche.com) ([@dfreniche](https://twitter.com/dfreniche))
 * **Bitarrays idea and original implementation**
   * Alberto García García (Blitzman, _albertgg93 (at) gmail (dot) com, [@algertgarcia93](http://twitter.com/algertgarcia93)_)
   * Pablo Martínez González (*pablo2093 (at) gmail (dot) com, [@pablo_2093](http://twitter.com/pablo_2093)*)
 * **Some original code and ideas for sprite drawing and firmware enabling/disabling**
   * Raúl Simarro (Artaburu / ESP Soft)
 * **Some makefile code and ideas**
   * [Cpcitor](http://github.com/cpcitor)
 * **Arkos player original code**
   * [Targhan](http://www.julien-nevo.com/) / [Arkos](http://www.cpcwiki.eu/index.php/Arkos)

### 3rdparty software authors
 
 * **[Arkos Tracker](http://www.grimware.org/doku.php/documentations/software/arkos.tracker/start)**
   * Main Author: [Targhan](http://www.julien-nevo.com/) / [Arkos](http://www.cpcwiki.eu/index.php/Arkos) 
   * Other Authors / Collaborators: SuperSylvestre / Les Sucres, 
   Augusto Ruiz Garcia (WYZ) / [Retroworks](http://www.retroworks.es), 
   Grim / [Arkos](http://www.cpcwiki.eu/index.php/Arkos), 
   [Lachlan Keown](http://www.twitter.com/lachlankeown), 
   Ramlaid / [Arkos](http://www.cpcwiki.eu/index.php/Arkos), 
   Madram / Overlanders
   UltraSyd / Brainstorm,
   [NoRecess](http://norecess.cpcscene.net/) / [Condense](http://www.pouet.net/groups.php?which=8),
   Syx
 * **[Small Devices C Compiler (SDCC)](http://sdcc.sourceforge.net/)**
   * [SDCC Team](http://sdcc.sourceforge.net/index.php#Who)
 * **[iDSK](http://koaks.amstrad.free.fr/amstrad/projets/)**
   * Sid / IMPACT 
   * [Pulkomandy](http://www.pushnpop.net/profile-47.html) / [Shinra Team](http://pulko.mandy.pagesperso-orange.fr/shinra/index.shtml)
 * **[Hex2bin](http://sourceforge.net/projects/hex2bin/)**
   * [Jaques Pelletier](https://www.linkedin.com/pub/jacques-pelletier/a/668/309)
 * **[2CDT](http://www.cpcwiki.eu/forum/applications/2cdt/)**
   * [Kevin Thacker](http://www.cpctech.org.uk/about.html) / [CPCTech](http://www.cpctech.org.uk/) 
 * **[Retro Game Asset Studio (RGAS)](http://www.cpcwiki.eu/index.php/Retro_Game_Asset_Studio)**
   * [Lachlan Keown](http://www.twitter.com/lachlankeown) (lachlankeown at gmail dot com)

#### Special Thanks

 * [Lachlan Keown](http://www.twitter.com/lachlankeown) (For being incredibly kind and helpful, and adding every required modification to better integrate RGAS with _**CPCtelera**_)
 * [Cpcitor](http://github.com/cpcitor) (for his great help and advice, and for developing [cpc-dev-tool-chain](http://github.com/cpcitor/cpc-dev-tool-chain))
 * [CPCWiki](http://cpcwiki.eu) & [Grimware](http://grimware.org/) (for providing great technical documentations and examples)
 * Raúl Simarro (for developing [CPCRSLib](http://sourceforge.net/projects/cpcrslib/) game creation library)
 * [Targhan](http://www.julien-nevo.com/) / [Arkos](http://www.cpcwiki.eu/index.php/Arkos) (for developing Arkos Traker&Player and giving great support on adding it to _**CPCtelera**_. Also for giving general advice during development of _**CPCtelera**_)
 * [Pulkomandy](http://www.pushnpop.net/profile-47.html) / [Shinra Team](http://pulko.mandy.pagesperso-orange.fr/shinra/index.shtml) (for maintaining [cpcsdk](https://github.com/cpcsdk), with tools like [iDSK](https://code.google.com/p/cpcsdk/downloads/detail?name=iDSK_015.7z&can=2&q=) or [cpcfs](https://code.google.com/p/cpcsdk/wiki/cpcfs), among others. For giving great advice and being helpful at every moment. Also for willing to give the best for CPC and maintain it alive)
 * Mochilote / [CPCMania](http://cpcmania.com) (for creating great tutorials and useful documentation in his site)
 * José Ángel Rodriguez ([@rvjose](http://twitter.com/rvjose)) (for early testing, bug reporting and giving great ideas)