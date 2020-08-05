FROM registry.cn-beijing.aliyuncs.com/troy-image/debian-custom:v0.1

ADD src /root/src/
ADD run.sh /root/
ADD build.sh /root/

RUN apt-get update && apt-get install -y gcc
RUN cd /root/ && bash build.sh


CMD ["/bin/bash", "-c", "cd /root && ./run.sh"]
