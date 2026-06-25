import time
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import ram_monitor # This is your custom C extension!

# Set up the figure and axis
fig, ax = plt.subplots()
x_data, y_data = [], []
line, = ax.plot([], [], 'b-', linewidth=2)

ax.set_title("Live System RAM Usage")
ax.set_xlabel("Time (seconds)")
ax.set_ylabel("RAM Used (MB)")
ax.set_xlim(0, 60) # Show 60 seconds of history
ax.set_ylim(0, 16000) # Adjust this based on your machine's total RAM

start_time = time.time()

def update(frame):
    # Call the C function to get memory data
    current_ram = ram_monitor.get_ram_usage()
    current_time = time.time() - start_time
    
    x_data.append(current_time)
    y_data.append(current_ram)
    
    # Keep only the last 60 seconds of data
    if current_time > 60:
        ax.set_xlim(current_time - 60, current_time)
        
    # Dynamically adjust the Y-axis if memory usage spikes
    if current_ram > ax.get_ylim()[1]:
        ax.set_ylim(0, current_ram + 2000)

    line.set_data(x_data, y_data)
    return line,

# Animate the graph, updating every 1000 milliseconds (1 second)
ani = FuncAnimation(fig, update, interval=1000, blit=False, cache_frame_data=False)

plt.tight_layout()
plt.show()
