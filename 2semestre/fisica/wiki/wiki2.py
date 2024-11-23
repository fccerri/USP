import sympy

vx, vy = sympy.symbols('v_x v_y')
vec_mod = sympy.sqrt(vx**2 + vy**2)
print("Resolução Algebrica em LaTeX:", sympy.latex(vec_mod))

ans = vec_mod.subs({vx:2.1, vy:7.2})
print("Resolução Numerica:", f'{ans:.1f}')