import sympy

a, w, b, t = sympy.symbols('a omega b t')

xt = a*sympy.cos(w*t)
yt = a*sympy.sin(w*t)
zt = b*t**2

dxt = xt.diff(t)
dyt = yt.diff(t)
dzt = zt.diff(t)

vec_mod = sympy.sqrt(dxt**2 + dyt**2 + dzt**2)
sympy.simplify(vec_mod)

print("Resolução Algebrica em LaTeX:", sympy.latex(vec_mod))
ans = vec_mod.subs({a:3.8, b:1.3, w:2, t:2.5})
print("Resolução Numerica:", f'{ans:.1f}')