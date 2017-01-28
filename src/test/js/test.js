var assert = require('assert');

var lockWindows = require('../../main/js');

describe('lock-your-windows', function(){
    describe('isLocked', function(){
        it('returns false when unlocked', function(){
            var actual = lockWindows.isLocked();
            var expected = false;
            assert.equal(actual, expected, "lockWindows should return false when Windows is unlocked (which I'm assuming it is right now)");
        });
    });
});