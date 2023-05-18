FROM gcc:9.2.0

WORKDIR usr/src/app


# RUN apt-get -qq update \
#     && apt-get -qq install --no-install-recommends cmake \ 
#     && apt-get clean
    
COPY . .

RUN make

CMD [ "./main" ]