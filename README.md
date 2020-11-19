### Hey! Welcome to my fork of dwm! Where suffering comes to die!

This is a *HEAVILY* modified version of dwm with a TON of patches and VERY well optimized!

Here's a list of the patches so far:

dwm-6.0-singularborders
dwm-6.0-singularborders_bstack
dwm-6.1-save_floats
dwm-actualfullscreen-20191112-cb3f58a
dwm-alwaysfullscreen-20160713-56a31dc
dwm-anybar-20200810-bb2e722
dwm-anybar-polybar-tray-fix-20200810-bb2e722
dwm-attachaside-6.1
dwm-autostart-20161205-bb3bd6f
dwm-centeredmaster-6.1
dwm-cyclelayouts-20180524-6.2
dwm-emptyview-6.0
dwm-fakefullscreen-20170508-ceac8c9
dwm-fullgaps-6.2
dwm-fullscreen-6.2
dwm-gaplessgrid-20160731-56a31dc
dwm-ipc-20200729-f04cac6
dwm-maximize_vert_horz-20160731-56a31dc
dwm-movestack-6.1
dwm-noborder-6.2
dwm-pertag-6.2
dwm-pertag-monitorrules-6.2
dwm-scratchpads-20200414-728d397b
dwm-sticky-6.1
dwm-swallow-20200707-8d1e703
dwm-uselessgap-6.2
dwm-warp-6.1

Also, I have added in some of instantWM's animations since I thought they looked cool, there's a way to disable them if you look closely in the config.h. (i'll actually just add
a button to toggle it in later releases)

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
  - libx11-dev
  - libxft-dev
  - libxinerama
  - yajl

Please, go into config.h and check the keybindings, you might see something you like!

After you have all of that, simply run ./makedwm.sh and it should compile to /usr/local/bin/dwm
