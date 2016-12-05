[About]
HTMLTag plug-in for Notepad++
Written by vor0nwe (Martijn Coppoolse) - http://martijn.coppoolse.com/software/
 using Delphi XE2
Part of the Npp-plugins project - http://sourceforge.net/projects/npp-plugins/
Hosted on http://fossil.2of4.net/npp_htmltag/


[Introduction]
This plug-in provides three core functions to Notepad++:
- HTML and XML tag jumping, like the built-in brace matching (Ctrl+B / Shift+Ctrl+B), and selection
  of tags and/or contents.
- HTML entity encoding/decoding (example: é to &eacute;)
- JS character encoding/decoding (example: é to \u00E9)

It originated in these requests on the Plugin Development forum on SourceForge.net:
- http://sourceforge.net/forum/message.php?msg_id=4284078
- http://sourceforge.net/forum/message.php?msg_id=4443898


[Installation]
As usual:  
Extract the DLL and accompanying files to the plugins folder under 
%ProgramFiles%\Notepad++ (or wherever you're running Notepad++ from) or %AppData%\Notepad++, and 
(re)start Np++.


[Usage]
- Ctrl+T to select the matching tag;
- Shift+Ctrl+T to select both tags and the entire contents in between. 

- Ctrl+E to encode all selected non-ASCII characters to their HTML entities;
- Shift+Ctrl+E to dEcode all selected HTML entities.
- Ctrl+J to encode all selected non-ASCII character to their Javascript entities;
- Shift+Ctrl+J to dEcode all selected JS entities.

All commands are available under the Plugins menu item 'HTML Tag'; the shortcut keys can be adjusted 
with the shortcut mapper.


[Files]
HTMLTag_ansi.dll        The ansi version of the plug-in, for Notepad++ versions up to and including
                        version 5.0.3. Note that this version will not be supported after v0.4.0.
HTMLTag_unicode.dll     The unicode version of the plug-in, for Notepad++ version 5.1 and up.
HTMLTag-entities.ini    This file contains the list(s) of entities that will be processed. For now,
                        only the list headed with [HTML 4] will be used.  This can be adjusted if
                        you want to use other entities.
HTMLTag-readme.txt      The file you're reading now.


[History]
- 0.5.0 - 2012-06-10 20:22
  * Fixed: crash on close of Notepad++
- 0.4.0 - 2011-09-03 22:46
  * Added: JS encoding
- 0.3.2 - 2010-11-07 19:30
  * Fixed: working workaround for change in Scintilla 2.2 with selection not being released
  * Changed: when selecting contents only, don't select whitespace at begin and end of contents
- 0.3.1 - 2010-11-03 18:00
  * Fixed: workaround for bug in Np++ 5.8.3 with selection not being released
  * Added: busy indicator in Windows 7+ task bar button (can be disabled in Config\HTMLTag.ini)
- 0.3.0 - 2009-11-29 20:30
  * Added: New plugin command to select tag contents only
  * Changed: Removed unnecessary units, reducing the file size of the DLL by 300KB
- 0.2.2 - 2008-08-24 21:20
  * Added: Unicode version for Notepad++ 5.1 and up
- 0.2.1 - 2008-02-22 21:07
  * Fixed: matching in XML files was case-inconsistent
  * Fixed: matching end tag did not take special characters in tag name into account
- 0.2 - 2007-10-20 20:10
  * Tag detection is now case-sensitive in XML files 
  * Added entity encoding/decoding
  * Uploaded the source to the Npp-plugins projects on SF.net
- 0.1 - 2007-08-05 20:00
  * Initial publication


[To do]
* [Request#1848503] Add a command to close the open tag at the current location
* Add command to encode entities in the contents only (only apply encoding when not inside tags;
  leave valid tags and entities alone)
* Add command to select tags only (and leave the contents out of the selection)
* Make it play nice(r) with PHP & ASP tags (either highlight those separately or ignore them)
* Add option to encode entities 'as-you-type'
* Add option to close tags 'as-you-type' (type '</' and the rest will be inserted automagically)
* [Request#2147949] drop down a list of tags after '<'
* [Request#2147949] drop down a list of attributes on space after a tag
