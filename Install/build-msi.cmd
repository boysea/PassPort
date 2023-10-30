@ECHO OFF
REM	Copyrignt (C) 2007 Piotr J. Socko (psocko@gmail.com)
REM
REM	This file is part of PassPort.
REM
REM PassPort is free software; you can redistribute it and/or modify
REM it under the terms of the GNU General Public License as published by
REM the Free Software Foundation; either version 2 of the License, or
REM (at your option) any later version.
REM
REM PassPort is distributed in the hope that it will be useful,
REM but WITHOUT ANY WARRANTY; without even the implied warranty of
REM MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
REM GNU General Public License for more details.
REM
REM You should have received a copy of the GNU General Public License
REM along with PassPort; if not, write to the Free Software
REM Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

candle.exe PassPort.wxs -ext WixUIExtension -ext WixNetFxExtension -out PassPort.wixobj
light.exe PassPort.wixobj -ext WixNetFxExtension -ext WixUIExtension -cultures:en-US -sval -b Licenses -out PassPort.msi