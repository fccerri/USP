import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

'''
Atividade 2: Simulação com Animação do Sistema Massa-Mola
    Aluno: Felipe Camargo Cerri
    Numero USP: 15451119
    23/11/2024  
    
'''

# Constantes do sistema
A = 3.0           # Amplitude 
phi = 2.0         # Fase inicial 
omega = 2.5     # Frequencia angular 
t_total = 5.0     # Tempo total de simulacao 
num_points = 500  # Numero de pontos na simulação

def spring_motion(A, phi, omega, t_total, num_points):
    """
    Calcula equação horária de um sistema massa-mola.

    Parâmetros:
      A (float): Amplitude do movimento em m.
      phi (float): Fase inicial em radianos.
      omega (float): Frequencia angular em rad/s.
      t_max (float): Tempo total da simulacao em s.
      num_points (int): Numero de pontos para a geração do vetor de tempo.

    Retorna:
      t : numpy.ndarray
          Vetor de tempo para o movimento do projetil
      x : numpy.ndarray
          Vetor de posicoes ao longo do tempo.
    """
    t = np.linspace(0, t_total, num=num_points)

    theta = phi + omega*t
    theta_rad = np.cos(theta)

    x = A*theta_rad

    return t, x

#Obtem os dados que serao utilizados
t, x = spring_motion(A, phi, omega, t_total, num_points)

#Configuracao do grafico
fig, ax = plt.subplots()
line, = ax.plot(t, x)

#Animacao
line, = ax.plot([], [], lw=2)
ax.set_xlim(0, t_total)
ax.set_ylim(-1.5 * A, 1.5 * A)


def update(frame):
    """
    Atualiza os dados da animação a cada frame dado.

    Parâmetros:
        frame (int): Frame atual da animação.

    Retorna:
        line : matplotlib.lines.Line2D
          linha da animacao atualizada para um dado frame de entrada.
    """
    line.set_data(t[:frame], x[:frame])
    return line,

# Cria animacao
ani = FuncAnimation(fig, update, frames=num_points, interval=20)

# Exibe
plt.show()
