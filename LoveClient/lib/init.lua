

-- 全局的引用
require("util")
class = require("middleclass")


local lib = {}

lib.ui = require("LoveFrames.init")
lib.net = require("LoverNet.lovernet")
lib.flux = require("flux.flux")

return lib
