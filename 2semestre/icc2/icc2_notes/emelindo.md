$$$$  
Do enunciado, temos a equação paramétrica do vetor posição:  
  
\[  
 \vec{r} = \left\{ \begin{array}{ll} x(t) = R \cos(\omega t)\\ y(t) = R \sin(\omega t) \\ z(t) = ct \end{array}  \right.  
\]  
  
  

### Questão 1

  
O vetor velocidade $\vec{v}$ representa a taxa de variação do vetor posição em relação ao tempo, isso é, a derivada de $\vec{r}$ em função do tempo.  
Dito isso, precisamos derivar $\vec{r}$:  
  
\[  
\dot{\vec{r}} = \vec{v} \left\{  \begin{array}{ll}  \dot{x}(t) = -\omega R \sin(\omega t) = - \omega y(t) \\ \dot{y}(t) = \omega R \cos(\omega t) = \omega x(t)\\ \dot{z}(t) = c \end{array}  \right.  
\]  
  
O módulo do vetor velocidade $\|\vec{v}\|$ por sua vez será alcançado através da seguinte equação, válida em bases ortonormais:  
\[  
\|\vec{v}\| = \sqrt{\vec{v} \cdot \vec{v}} = \sqrt{\dot{x}(t)^2 + \dot{y}(t)^2 + \dot{z}(t)^2}  
\]  
  
Substituindo os valores, temos:  
\[  
\|\vec{v}\| = \sqrt{\omega^2 R^2 \sin^2(\omega t) + \omega^2 R^2 \cos^2(\omega t) + c^2} = \sqrt{\omega^2 R^2 (\sin^2(\omega t) + \cos^2(\omega t)) + c^2}  
\]  
  
A partir da relação fundamental da trigonometria $\cos^2(x) + \sin^2(x) = 1$:  
\[  
\|\vec{v}\| = \sqrt{\omega^2 R^2 + c^2}  
\]  
  
$\vec{r}$  
##### Análise dimensional

$ [\vec{r}] = L $, Portanto $ \left[\frac{d\vec{r}}{dt}\right] = \frac{L}{T} = [\vec{v}] $ 
  
Além disso, em $\sin(x)$, $x$ é adimensional, como $[t] = T$, logo $[\omega] = T^{-1}$.  
  
Temos:  
\[  
[\|\vec{v}\|] = \sqrt{[\omega^2] [R^2]} = \sqrt{\frac{L^2}{T^2}} = \frac{L}{T}  
\]  
  

### Questão 2

  
A aceleração, por sua vez, é a taxa de variação do vetor velocidade em relação ao tempo. Desse modo, podemos utilizar os mesmos artifícios do item 1 para obtermos o vetor $\vec{a}$.  
Derivada de $\vec{v}$ em relação a $t$:  
  
\[  
\dot{\vec{v}} = \vec{a}  
\left\{  
\begin{array}{ll}  
\ddot{x}(t) = -\omega^2 R \cos(\omega t) = -\omega^2 x(t)\\  
\ddot{y}(t) = -\omega^2 R \sin(\omega t) = -\omega^2 y(t) \\  
\ddot{z}(t) = 0  
\end{array}  
 \right.  
\]  
  
Note que o sinal negativo indica sentido oposto ao vetor $\vec{r}$, além disso, $\vec{a}$ é a segunda derivada do vetor $\vec{r}$.  
  
Da mesma forma, podemos obter $\|\vec{a}\|$ a partir da equação:  
\[  
\|\vec{a}\| = \sqrt{\vec{a} \cdot \vec{a}} = \sqrt{\ddot{x}(t)^2 + \ddot{y}(t)^2 + \ddot{z}(t)^2}  
\]  
  
Então: \[\|\vec{a}\| = \sqrt{\omega^4 R^2 \cos^2(\omega t) + \omega^4 R^2 \sin^2(\omega t) + 0} = \sqrt{\omega^4 R^2 (\cos^2(\omega t) + \sin^2(\omega t))}  
\]  
  
$ \therefore \|\vec{a}\| = \sqrt{\omega^4 R^2} = \omega^2 R $  
  

##### Análise Dimensional

$[\vec{v}] = \frac{L}{T}$ Portanto,$ \left[\frac{d\vec{v}}{dt}\right] = \frac{L}{T^2} = [\vec{a}] $  
  
Além disso,  
\[  
[\|\vec{a}\|] = [\omega^2][R] = \frac{L}{T^2}  
\]  
  

### Questão 3

  

#### Parte 1

Podemos deduzir a seguinte propriedade:

  

Dado um vetor $\vec{d}$, temos: \[\|\vec{d}\| = d = \sqrt{\vec{d} \cdot \vec{d}} \therefore d^2 = \vec{d} \cdot \vec{d}  
\]  
Se assumirmos que o vetor $\vec{d}$ tem módulo constante, temos:\[\dot{d} = 0\], por definição  
Assim:\[ \dot{d^2} = (\vec{d} \cdot \vec{d})'  
\]  
\[  
2d\, \dot{d} = 2 \vec{d} \cdot \dot{\vec{d}} \implies 0 = \vec{d} \cdot \dot{\vec{d}} \iff \vec{d} \perp \dot{\vec{d}}  
\]  

Uma vez que o produto escalar representa a projeção de um vetor no outro.

  

Portanto, a derivada de um vetor de módulo constante gera um vetor ortogonal a ele de tal forma que:\[ \vec{d} \cdot \dot{\vec{d}} = 0 \]

E como $\vec{a} = \dot{\vec{v}}$ e $\vec{v}$ tem módulo constante, podemos concluir que:  
\[  
\vec{a} \cdot \vec{v} = 0  
\]  
  

#### Parte 2  

O comprimento de uma trajetória curvilínea está intimamente ligado ao conceito de integral.  
Dito isso, podemos pensar da seguinte forma:  
É possível aproximar o comprimento $\Delta S$ somando cordas $\Delta \vec{r_i}$ que representam a variação do vetor posição $\vec{r}$ em relação ao tempo.  
![Rascunho retirado da prova](https://edisciplinas.usp.br/draftfile.php/8221268/user/draft/559050742/Captura%20de%20tela%202024-09-14%20234857.png?time=1726369307828)  
Note que: $\Delta S \geq \|\Delta \vec{r_i} + \Delta \vec{r_{i+1}}\|$.  
  
No entanto, quanto mais "$\Delta \vec{r_i}$" incluirmos no cálculo de $\Delta S$, mais próximos chegaremos da resposta.  
  
Vamos definir $\|\Delta \vec{r_i}\| = \|\vec{r_i} - \vec{r_{i+1}}\|$ e $\Delta S \geq \sum_{j=0}^n \|\Delta \vec{r_i}\|$.  
  
Podemos então relacionar $\Delta \vec{r_i}$ com a velocidade da seguinte forma:  
\[  
\|\Delta \vec{r_i}\| = \sqrt{\vec{r_i} \cdot \vec{r_i}} = \sqrt{\left(\frac{\Delta \vec{r_i}}{\Delta t_i}\right) \cdot \left(\frac{\Delta \vec{r_i}}{\Delta t_i}\right)} \Delta t_i = \|\vec{v}\| \Delta t_i  
\]  
  
\[  
\therefore \Delta S \geq \sum_{i=0}^n V_i \Delta t_i  
\]  
  
Note que $n \rightarrow \infty \implies \Delta t \rightarrow 0$, de forma que podemos utilizar a ferramenta limite para alcançar o resultado desejado:  
\[  
\therefore \Delta S = \lim_{n \to \infty} \sum_{i=0}^n V_i \Delta t_i = \int_{t_i}^{t_f} v \, dt  
\]  
  

Assim, aplicando as informações fornecidas e obtidas nos itens anteriores, temos:

\[  
\Delta S = \displaystyle\int_{0}^{T} \sqrt{\omega^2 R^2 + c^2} \,dt = \sqrt{\omega^2 R^2 + c^2} \int_{0}^{T} dt = \sqrt{\omega^2 R^2 + c^2} \left(t + k \right) \Bigg|_{0}^{T} = T \sqrt{\omega^2 R^2 + c^2} = \frac{2\pi}{\omega} \sqrt{\omega^2 R^2 + c^2}  
\]  
  

  

##### Analise Dimensional  

\[  
[\Delta S] = \left[\int v \, dt\right] = \frac{L}{T}  T = L  
\]  
  

  

#### Parte 3

A distância L por sua vez pode ser obtida mais facilmente, através d diferença dos vetores $\vec{r_{tf}}$ e $\vec{r_{ti}}$ 

\[ \therefore L = \left\| \vec{r_{(T)}} - \vec{r_{(0)}} \right\| \]

  

\[  
 \vec{r_{(T)}} =  \left\{  \begin{array}{ll}  x_{(T)} = R\cos{\left(\frac{2\pi}{\omega} \omega \right)} = R \\  y_{(T)} = R\sin{\left(\frac{2\pi}{\omega}  \omega \right)} = 0 \\  z_{(T)} = \frac{2\pi}{\omega}\, c  \end{array}  \right.  
\]  
  
\[  
 \vec{r_{(0)}} = \left\{  \begin{array}{ll} x_{(0)} = R\cos{(0)} = R \\  y_{(0)} = R\sin{(0)} = 0 \\ z_{(0)} = 0  \end{array} \right.  
\]  
  
Finalmente podemos calcular o vetor resultante a partir da equação:  
\[  
L = \sqrt{(R - R)^2 + (0 - 0)^2 + (\frac{2\pi}{\omega}\,c - 0)^2} = \sqrt{(\frac{2\pi}{\omega})^2 c^2}  
= \frac{2\pi}{\omega}c = T\,c  
\]

  

Assim, podemos concluir que mesmo que $\Delta S$ e $L $ estejam intrinsecamente interligados são conceitos distintos, visto que um é o módulo da diferença de dois vetores e o outro é a integral do módulo da velocidade em relação ao tempo. Além disso, foi possível verificar que a relação: $\Delta S \geq \|\Delta \vec{r_i} + \Delta \vec{r_{i+1}}\|$ anteriormente proposta é válida como esperado.

  

##### Análise Dimensional  

$z_{(t)}$ é uma coordenada espacial e portanto $[z_{(t)}] = L$

Como $z_{(t)} = tc$ podemos concluir que $[c] = \frac{L}{T}$

Dessa forma temos:  
$[ \Delta S] = [\frac{2\pi}{\omega}c] = T \frac{L}{T} = L$

  
  

### Questão 4

Podemos decompor o vetor velocidade $\vec{v}$ para obetermos relações importantes  
$\vec{v} = v\, \hat{v}$ , Assim \[ \vec{a} = \dot{\vec{v}} = \dot{v} \hat{v} + v \dot{\hat{v}} \] Lembrando que $\dot{v} = 0$ e \[ \vec{v} \perp \dot{\vec{v}} \]

  

Dessa forma, através das conclusões feitas no item 3 podemos escrever, por convenção, $\vec{a}$ da forma: $\vec{a} =V^2 \,\kappa \, \hat{n}$, em que $\hat{n}$ é o versor da normal e $\kappa$ é a curvatura.

  

De maneira algébrica, podemos desenvolver:

$ \|\vec{v} \times \vec{a}\| = V^2 \, \kappa \, \| \vec{v} \times \hat{n}\|$ e como $\|\hat{n}\| = 1$, temos $\|\vec{v} \times \hat{n}\| = \| \{\vec{v} \| = V$

  

$ \therefore \kappa = \frac{\|\vec{v} \times \vec{a}\|}{V^3}$  

  

Pela definição de produto vetorial chegamos em: \[ \|\vec{v} \times \vec{a}\| = V \cdot A \cdot \sin{\theta} \] e como \(\vec{a} \perp \vec{v} \implies \sin{\theta} = 1\)

Temos que: \[\kappa = \frac{V \, A}{V^3} = \frac{A}{V^2} = \frac{\omega^2 \, R}{\omega^2 \, R^2 + c^2} \]

  

##### Análise dimensional

$[\kappa] = \frac{[A]}{[V^2]} = \frac{L \, T^{-2}}{(L \, T^{-1})^2} = L^{-1}$