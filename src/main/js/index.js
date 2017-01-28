var winlock = require('../../../target/winlock.node');

/**
 * @return Boolean true if Windows is currently locked, and false if Windows is unlocked
 */
module.exports.isLocked = function(){
    return winlock.isLocked();
};

/**
 * Locks Windows, as if the user pressed Win+L
 */
module.exports.lock = function(){
    winlock.lock();
};