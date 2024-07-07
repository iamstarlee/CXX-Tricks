<div align=center>
  <img src="https://github.com/iamstarlee/CXX-Tricks/assets/44799727/2c590a60-8d87-46ff-88f7-58569b9123d8">
</div>

<br>
在 NVIDIA ，我们以各种方式使用容器，包括开发、测试、基准测试，当然还有生产中的容器，作为通过 NVIDIA DGX-1 的云管理软件部署深度学习框架的机制。 Docker 改变了我们管理工作流程的方式。使用 Docker ，我们可以在工作站上开发和原型化 GPU 应用程序，然后在任何支持 GPU 容器的地方发布和运行这些应用程序。

在本文中，我们将介绍 Docker 容器；解释 NVIDIA Docker 插件的好处；通过构建和部署一个简单的 CUDA 应用程序的示例；最后演示如何使用 NVIDIA Docker 运行当今最流行的深度学习应用程序和框架，包括 DIGITS 、 Caffe 和 TensorFlow 。
<br/>
# Docker简介
Docker 容器是一种将 Linux 应用程序与其所有库、数据文件和环境变量捆绑在一起的机制，以便在运行的任何 Linux 系统上以及在同一主机上的实例之间，执行环境始终是相同的。 Docker 容器仅为用户模式，因此来自容器的所有内核调用都由主机系统内核处理。

Docker 容器将一个软件包在一个完整的文件系统中，该文件系统包含运行所需的一切：代码、运行时、系统工具、系统库——任何可以安装在服务器上的东西。这保证了软件无论其环境如何，都将始终运行相同的程序。

区分容器和基于 hypervisor 的虚拟机（ vm ）很重要。 vm 允许操作系统的多个副本，甚至多个不同的操作系统共享一台机器。每个虚拟机可以承载和运行多个应用程序。相比之下，容器被设计成虚拟化单个应用程序，并且部署在主机上的所有容器共享一个操作系统内核，如下图 所示。通常，容器运行速度更快，以裸机性能运行应用程序，并且更易于管理，因为进行操作系统内核调用没有额外的开销。

<div align=center>
  <img src = "https://github.com/iamstarlee/CXX-Tricks/assets/44799727/5d1ac5ef-8b9a-44cf-b14b-9aca7f7d6b9a">
</div>

Docker 提供了硬件和软件封装，允许多个容器同时在同一个系统上运行，每个容器都有自己的资源集（ CPU 、内存等）和它们自己的专用依赖集（库版本、环境变量等）。 Docker 还提供了可移植的 Linux 部署： Docker 容器可以在任何内核为 3 . 10 或更高版本的 Linux 系统上运行。自 2014 年以来，所有主要的 Linux 发行版都支持 Docker 。封装和可移植部署对于创建和测试应用程序的开发人员以及在数据中心运行应用程序的操作人员都很有价值。

Docker 提供了许多更重要的功能:
- Docker强大的命令行工具“ Docker build ”，使用“ Dockerfile ”中提供的描述，从源代码和二进制文件创建 Docker 映像。
- Docker的组件架构允许一个容器映像用作其他容器的基础。
- Docker提供容器的自动版本控制和标签，优化了组装和部署。 Docker 映像由版本化的层组合而成，因此只需要下载服务器上缺少的层。
- Docker Hub 是一项服务，它可以方便地公开或私下共享 Docker 图像。
- 容器可以限制在一个系统上有限的一组资源（例如一个 CPU 内核和 1GB 内存）。
- Docker 提供了一个[分层文件系统](https://docs.docker.com/storage/storagedriver/)，它可以节省磁盘空间，并构成可扩展容器的基础。

# Why Nvidia Docker ?
Docker 容器与平台无关，但也与硬件无关。当使用特殊的硬件，如 NVIDIA GPUs 时，这就产生了一个问题，这些硬件需要内核模块和用户级库来操作。因此， Docker 本机不支持容器中的 NVIDIA GPUs 。

解决这个问题的早期解决方案之一是在容器中完全安装 NVIDIA 驱动程序，并在启动时映射到与 NVIDIA GPUs （例如 /dev/nvidia0 ）对应的字符设备中。此解决方案很脆弱，因为主机驱动程序的版本必须与容器中安装的驱动程序版本完全匹配。这一要求大大降低了这些早期容器的可移植性，破坏了 Docker 更重要的特性之一。

为了使 Docker 映像能够利用 NVIDIA GPUs 实现可移植性，我们开发了 nvidia-docker ，这是一个托管在 Github 上的开源项目，它提供了基于 GPU 的可移植容器所需的两个关键组件：
- 与驱动程序无关的 CUDA 图像；以及
- Docker 命令行包装器，在启动时将驱动程序和 GPUs （字符设备）的用户模式组件装入容器。
nvidia-docker 本质上是围绕 docker 命令的包装器，它透明地为容器提供了在 GPU 上执行代码所需的组件。只有在使用 nvidia-docker run 来执行使用 GPUs 的容器时才是绝对必要的。但为了简单起见，在本文中，我们将其用于所有 Docker 命令。






1. [NVIDIA Docker：让 GPU 服务器应用程序部署变得容易](https://developer.nvidia.com/zh-cn/blog/nvidia-docker-gpu-server-application-deployment-made-easy/)
