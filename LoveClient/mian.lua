

ab = require("lib.init")
local Font = love.graphics.newFont("res/font/default.ttf",18)
function love.load()

	ab.director:init()


end
function love.draw()
	love.graphics.setFont(Font)	
	love.graphics.print("你好 中国",100,100)
	ab.director:draw()
end
function love.update(dt)
	ab.director:update(dt)
end
function love.keypressed(key,isrepeat)

end
function love.keyreleased(key)

end


function love.mousepressed(x,y,button)

end

function love.mousereleased(x,y,button)

end

function love.textinput(key)

end

function love.resize()

end
