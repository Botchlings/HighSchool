"""31308 김수민 물리학2 발표"""

import turtle as t
import math

t.setup(1200,600)
t.shape("circle")
t.shapesize(0.3, 0.3, 0)
m = int(t.textinput('질량(kg)', '물체의 질량을 입력하세요.'))
v = int(t.textinput('속도(m/s)', '수평 방향 속도를 입력하세요.'))
          
def draw_pos(x,y):
    t.hideturtle()
    t.penup()
    t.setx(x)
    t.sety(y)
    t.stamp()
    hl= -(t.window_height() / 2)
    tm=0
    
    
    while True:
        X = (v) * tm
        Y = - (10*tm*tm*(1/2))
        nx = x + int(X)
        ny = y + int(Y)
        if ny >= -300:
            t.goto(nx, ny)
            t.stamp()
            tm = tm + 1
        else:
            break

draw_pos(-580,280)
print("구분         "+"     "+"수평(x축)방향"+"     "+"연직(y축)방향")
print("알짜힘       "+"     "+"  F = 0"+"     "+"        F = "+str(m)+"*g")
print("가속도       "+"     "+"  a = 0"+"     "+"        a = g")
print("처음속도     "+"     "+"  V0 = "+str(v)+"     "+"     V0 = 0")
print("t초 때의 속도"+"     "+"  V = "+str(v)+"     "+"      V = gt")
print("t초 때의 변위"+"     "+"  "+str(v)+"*t"+"     "+"        1/2*g*t^2")
t.done()
