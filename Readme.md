lock-your-windows
============

Activate the Windows lock screen (Win+L), or check if Windows is currently locked.

## Requirements

- [Node.js and NPM](https://nodejs.org/en/)
- [node-gyp](https://www.npmjs.com/package/node-gyp)
- [Visual Studio](https://www.visualstudio.com/downloads/) (tested on 2015 Community Edition)
- [Windows 8.1 SDK](https://developer.microsoft.com/en-us/windows/downloads/windows-8-1-sdk)

## Installation
```bash
npm install --save lock-your-windows
```

## Usage

```javascript
var lockYourWindows = require('lock-your-windows');

var isLocked = lockYourWindows.isLocked();
console.log("Windows is currently "+(isLocked ? "locked" : "unlocked"));

console.log("Locking Windows...");
lockYourWindows.lock();
```

## Developing

### Recompile the native C++ addon

```bash
node-gyp rebuild
```

### Run tests

```bash
npm test
```