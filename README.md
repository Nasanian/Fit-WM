### Hey! Welcome to my fork of dwm! Where suffering comes to die!

This is a *HEAVILY* modified version of dwm with a *TON* of patches! <br/>
*With no crap included*

Here's a list of the patches so far:

dwm-6.0-singularborders<br/>
dwm-6.0-singularborders_bstack<br/>
dwm-6.1-save_floats<br/>
dwm-actualfullscreen-20191112-cb3f58a<br/>
dwm-alwaysfullscreen-20160713-56a31dc<br/>
dwm-anybar-20200810-bb2e722<br/>
dwm-anybar-polybar-tray-fix-20200810-bb2e722<br/>
dwm-attachaside-6.1<br/>
dwm-autostart-20161205-bb3bd6f<br/>
dwm-centeredmaster-6.1<br/>
dwm-cyclelayouts-20180524-6.2<br/>
dwm-emptyview-6.0<br/>
dwm-fakefullscreen-20170508-ceac8c9<br/>
dwm-fullgaps-6.2<br/>
dwm-fullscreen-6.2<br/>
dwm-gaplessgrid-20160731-56a31dc<br/>
dwm-ipc-20200729-f04cac6<br/>
dwm-maximize_vert_horz-20160731-56a31dc<br/>
dwm-movestack-6.1<br/>
dwm-noborder-6.2<br/>
dwm-pertag-6.2<br/>
dwm-pertag-monitorrules-6.2<br/>
dwm-scratchpads-20200414-728d397b<br/>
dwm-sticky-6.1<br/>
dwm-swallow-20200707-8d1e703<br/>
dwm-uselessgap-6.2<br/>
dwm-warp-6.1<br/>
<br/>

Also, I have added in some of instantWM's animations since I thought they looked cool, there's a way to disable them if you look closely in the config.h. (i'll actually just add
a button to toggle it in later releases)

I've also made sure to make some changes to it in order to have it run better with games. (Tested my entire steam library) <br/>
You also don't need to kill dwm anymore to make changes! *JUST RECOMPILE AND PRESS SHIFT + MOD(Alt by default) + R*

I plan to add in vanity gaps in place of the current gaps and i'm soon to work on fixing the swallowing not working properly (for some odd reason...). Enjoy!

### HOW TO BUILD

You will need:
  - A brain
  - Patience
  - A caffeinated beverage of your choosing.

Dependencies:
  - st (i have a fork i'll be uploading soon)
  - dmenu (i have a fork of this too)
  - xorg
  - libxcb
  - gcc
  - libx11-dev / libx11 (Could be different depending on distro) 
  - libxft-dev / libxft (Could be different depending on distro)
  - libxinerama
  - yajl
  - make

Please, go into config.h and check the keybindings, you might see something you like!

After you have all of that, simply run ./makedwm.sh and it should compile to /usr/local/bin/dwm
